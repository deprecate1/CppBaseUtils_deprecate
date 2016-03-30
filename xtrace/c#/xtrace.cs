using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Drawing;
using System.Windows;

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
                string temp_path = System.IO.Path.GetTempPath() + "xTrace.dll";
                //string temp_path = System.IO.Path.GetTempPath() + "xTrace64.dll";
                                hLib = LoadLibrary(temp_path);
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

                private static int ColorToCOLORREF(System.Drawing.Color color) 
                { 
                        return ((color.R | (color.G << 8)) | (color.B << 0x10)) & 0xffffff;
                }

                public static void trace(System.Drawing.Color c, string format, params object[] args)
                {
                        dllLoad();
                        if (null == hPorc)
                                return;
                        int value = ColorToCOLORREF(c);
                        DateTime dt = DateTime.Now;
                        string tm1 = string.Format("{0:yyyy-MM-dd HH:mm:ss: }", dt);
                        hPorc(1, value, tm1, 0, 0);
                        hPorc(1, value, string.Format(format, args), 0, 0);
                }

	        public static void trace(string format, params object[] args)
	        {
                        dllLoad();
                        if (null == hPorc)
                                return;
                        int value = ColorToCOLORREF(System.Drawing.Color.FromArgb(0, 0, 0));
                        DateTime dt = DateTime.Now;
                        string tm1 = string.Format("{0:yyyy-MM-dd HH:mm:ss: }", dt);
                        hPorc(1, value, tm1, 0, 0);
                        hPorc(1, value, string.Format(format, args), 0, 0);
	        }

		public static void trace(byte[] buf, int len)
		{
			trace(System.Drawing.Color.FromArgb(0, 0, 0), buf, len);
		}

		public static void trace(System.Drawing.Color c, byte[] buf, int len)
		{
			const int LINE_PRINT_COUNT = 16;
			int line = len / LINE_PRINT_COUNT + 1;

			string output = "";
			for (int i = 0; i < line; i++)
			{
				for (int j = 0; j < LINE_PRINT_COUNT; j++)
				{
					output += String.Format("{0:X2} ", buf[i*LINE_PRINT_COUNT + j]) + ", ";

					if (i*LINE_PRINT_COUNT + j + 1 == len)
						break;

				}
				output += "\n";
				trace(c, output);
				output = "";
			}
		}
	}
}
