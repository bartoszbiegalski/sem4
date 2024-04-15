using System;

namespace GFNamespace {
	public class Program {
		public static void Main() {
			GF first = new GF(13, 4);
			GF second = new GF(13, 14);

			Console.WriteLine(first);

			Console.WriteLine(first>=second);

			Console.WriteLine(first<=second);

			Console.WriteLine(first<=second);

		}
	}
}
