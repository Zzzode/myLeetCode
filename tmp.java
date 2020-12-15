public int matrixScore(int[][] A) {
    //结果，列号和行号 下标从0开始
    int result = 0, columnNum = A[0].length - 1, rowNum = A.length - 1;

    //记录第一个数字为0的行的行号
    List<Integer> startsWithZero = new ArrayList<Integer>();
    for (int i = 0; i <= rowNum; i++) {
        if (A[i][0] == 0) startsWithZero.add(i);
    }
    //如果第一列全部为0，直接反转第一列，不需要记录行号去反转行
    if (startsWithZero.size() == A.length) startsWithZero.clear();

    //记录矩阵当前列的十进制和
    int temp = 0;
    //当前列的次幂
    int power = 0;
    //外层循环为列号(倒序)
    for (int i = columnNum; i > 0 ; i--,power++,temp = 0) {

        //当前列的十进制最大和，即当前列每行都为1
        double maxSum;

        //内层循环为行号
        for (int j = 0; j <= rowNum; j++) {
            //如果当前行第一位数字为0，则当前行全部反转
            if (startsWithZero.indexOf(j) > -1) temp += A[j][i] == 0? Math.pow(2, power): 0;
            else temp += A[j][i] == 1? Math.pow(2, power): 0;
        }

        //每列取1的数量更多的反转可能
        result += temp > (maxSum = Math.pow(2, power) * A.length) / 2? temp: maxSum - temp;
    }

    //前面计算出了第二列到最后一列的和，加上第一列的和(第一列全部反转为1)
    return (int)(result + Math.pow(2, columnNum) * A.length);
}
