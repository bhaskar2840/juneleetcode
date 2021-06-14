class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
        int res = 0;
        for(int i = 0; i < boxTypes.length; i++) {
            res += Math.min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= Math.min(truckSize, boxTypes[i][0]);
            if(truckSize == 0)
                break;
        }
        return res;
    }
}
