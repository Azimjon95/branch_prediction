public class BranchPredictionExample {
    public static void main(String[] args) {
        int[] arr = new int[1000000];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i % 2; // Alternating values for branch misprediction
        }

        long startTime = System.nanoTime();
        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                sum++;
            }
        }

        long endTime = System.nanoTime();
        System.out.println("Execution Time: " + (endTime - startTime) + " ns");
    }
}
