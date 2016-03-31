using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Drawing;
using System.Windows;

namespace System
{
	public class XTRACE
	{
		[DllImport("kernel32.dll")]  private extern static IntPtr LoadLibrary(string path);
		[DllImport("kernel32.dll")]  private extern static IntPtr GetProcAddress(IntPtr lib, string funcName);
		[DllImport("kernel32.dll")]  private extern static bool FreeLibrary(IntPtr lib);

		[UnmanagedFunctionPointer(CallingConvention.Cdecl)]
			private delegate void MagicTraceProc(int type, int color, IntPtr output, int void1, int void2);

		private static IntPtr           hLib  = IntPtr.Zero;
		private static MagicTraceProc   hPorc = null;
		private static void dllLoad()
		{
			if (IntPtr.Zero == hLib)
			{
				const int nChars = 128;
				string temp_path = System.IO.Path.GetTempPath() + "xTrace.dll";
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

		private static void __trace(int color, string output)
		{
			dllLoad();
			if (null == hPorc)
				return;
			hPorc(1, color, Marshal.StringToBSTR(output), 0, 0);
		}

		private static int ColorToCOLORREF(System.Drawing.Color color) 
		{ 
			return ((color.R | (color.G << 8)) | (color.B << 16)) & 0xffffff;
		}

                public static void print(System.Drawing.Color c, string format, params object[] args)
                {
                        int color = ColorToCOLORREF(c);
                        __trace(color, format);
                }

                public static void print(string format, params object[] args)
                {
                        System.Drawing.Color color = System.Drawing.Color.FromArgb(0, 0, 0);
                        print(color, format, args);
                }

                public static void printex(System.Drawing.Color c, string format, params object[] args)
		{
			int color = ColorToCOLORREF(c);
			DateTime dt = DateTime.Now;
			string tm1 = string.Format("{0:yyyy-MM-dd HH:mm:ss: }", dt);

			__trace(color, tm1);
			__trace(color, format);
		}

		public static void printex(string format, params object[] args)
		{
			System.Drawing.Color color = System.Drawing.Color.FromArgb(0, 0, 0);
                        printex(color, format, args);
		}

		public static void print(byte[] buf, int len)
		{
                        print(System.Drawing.Color.FromArgb(0, 0, 0), buf, len);
		}

		public static void print(System.Drawing.Color c, byte[] buf, int len)
		{
			const int LINE_PRINT_COUNT = 16;
			int line = len / LINE_PRINT_COUNT;

			string output = "";
                        int i;

                        // ÕûÐÐ
			for (i = 0; i < line; i++)
			{
                                output = "";
                                output += String.Format("{0:X8}:  ", i);
                                for (int j = 0; j < LINE_PRINT_COUNT; j++)
				{
					output += String.Format("{0:X2} ", buf[i*LINE_PRINT_COUNT + j]);

                                        if (LINE_PRINT_COUNT / 2 - 1 == j)
                                                output += " ";
                                }
                                output += " |  ";
                                for (int j = 0; j < LINE_PRINT_COUNT; j++)
                                {
                                        byte byte1 = buf[i * LINE_PRINT_COUNT + j];
                                        if (byte1 >= 0x20 && byte1 <= 0x7e)
                                                output += Char.ToString((char)byte1);
                                        else
                                                output += ".";

                                        if (LINE_PRINT_COUNT / 2 - 1 == j)
                                                output += " ";
                                }
                                output += "\n";
                                print(c, output);
                        }

                        // Ê£ÓàµÄ
                        int start = len / LINE_PRINT_COUNT * LINE_PRINT_COUNT;
                        int leave = len - start;
                        if (leave <= 0)
                                return;

                        output = "";
                        output += String.Format("{0:X8}:  ", i);
                        for (i = start; i < len; i++)
                        {
                                output += String.Format("{0:X2} ", buf[i]);
                                if (start + LINE_PRINT_COUNT / 2 - 1 == i)
                                        output += " ";
                        }
                        for (i = len; i < start + LINE_PRINT_COUNT; i++)
                        {
                                output += "   ";
                                if (start + LINE_PRINT_COUNT / 2 - 1 == i)
                                        output += " ";
                        }
                        output += "\n";
                        print(c, output);
                }
	}
}
