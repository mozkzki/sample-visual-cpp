import java.io.*;

public class LibraryJava {

	private native int execute();

	public static void main(String[] args) {
		scanf("ŠJn‚·‚é‚É‚ÍEnter‚ğ“ü—Í");

		System.loadLibrary("library_jni_wrapper");
		LibraryJava me = new LibraryJava();

		int result = me.execute();
		System.out.println("result=" + result);

		scanf("I—¹‚·‚é‚É‚ÍEnter‚ğ“ü—Í");
	}

	private static void scanf(String message) {
		System.out.println(message);

		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		try {
			br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
