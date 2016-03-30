using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Drawing;
using System.Windows.Media;

namespace System
{
	public class XTRACE
        {
                [DllImport("kernel32.dll")]
                private extern static IntPtr LoadLibrary(string path);
                [DllImport("kernel32.dll")]
                private extern static IntPtr GetProcAddress(IntPtr lib, string funcName);
                [DllImport("kernel32.dll")]
                private extern static bool FreeLibrary(IntPtr lib);
                [DllImport("kernel32.dll")]
                private static extern void GetSystemDirectory(StringBuilder SysDir, int count);
                private delegate bool MagicTraceProc(int type, int color, string output, int void1, int void2);

                private static IntPtr           hLib  = IntPtr.Zero;
                private static MagicTraceProc   hPorc = null;
                private static void dllLoad()
                {
                        if (IntPtr.Zero == hLib)
                        {
                                const int nChars = 128;
                                StringBuilder sb = new StringBuilder(nChars);
                                GetSystemDirectory(sb, nChars);
                                string dll_path = sb.ToString() + "\\xTrace.Dll";
                                hLib = LoadLibrary(dll_path);
                        }

                        if (IntPtr.Zero == hLib)
                                return;

                        if (null == hPorc)
                        {
                                hPorc = (MagicTraceProc)Invoke("MagicTraceProc", typeof(MagicTraceProc));
                        }
                }

                private static Delegate Invoke(string APIName, Type t)
                {
                        IntPtr api = GetProcAddress(hLib, APIName);
                        return (Delegate)Marshal.GetDelegateForFunctionPointer(api, t);
                }

                private static int ColorToCOLORREF(Color color) 
                { 
                        return ((color.R | (color.G << 8)) | (color.B << 0x10)) & 0xffffff;
                }

                public static void trace(Color c, string format, params object[] args)
                {
                        dllLoad();
                        if (null == hPorc)
                                return;
                        int value = ColorToCOLORREF(c);
                        hPorc(1, value, string.Format(format, args), 0, 0);
                }

	        public static void trace(string format, params object[] args)
	        {
                        dllLoad();
                        if (null == hPorc)
                                return;
                        int value = ColorToCOLORREF(Color.FromRgb(0, 0, 0));
                        hPorc(1, value, string.Format(format, args), 0, 0);
	        }
	}
}
