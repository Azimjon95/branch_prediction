public class TimingLeakExample {
    public static boolean insecureCheck(String input, String correct) {
        // Bad case: Branching based on secret value
        for (int i = 0; i < correct.length(); i++) {
            if (input.charAt(i) != correct.charAt(i)) {
                return false; // Timing leak occurs here
            }
        }
        return true;
    }

    public static boolean secureCheck(String input, String correct) {
        // Good case: Constant-time comparison (prevents timing attacks)
        int diff = 0;
        for (int i = 0; i < correct.length(); i++) {
            diff |= input.charAt(i) ^ correct.charAt(i);
        }
        return diff == 0;
    }

    public static void main(String[] args) {
        String correctPassword = "secure123";
        String input = "secure123";

        long start = System.nanoTime();
        boolean result = insecureCheck(input, correctPassword);
        long end = System.nanoTime();
        System.out.println("Insecure Check Time: " + (end - start) + " ns, Result: " + result);

        start = System.nanoTime();
        result = secureCheck(input, correctPassword);
        end = System.nanoTime();
        System.out.println("Secure Check Time: " + (end - start) + " ns, Result: " + result);
    }
}
