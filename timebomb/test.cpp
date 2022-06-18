class second{
    int size;
    int data[];

    second(int d[]){
        this.size = d.length;
        this.data = new int[this.size];
        for (int i = 0; i < this.size; i++) {   data[i] = d[i]; }
    }

    int getSecond(){
        int sec = 0x7FFFFFFF;
        int minIndex = findMinimum(data);
        int remainder = -1;
        int currentRound[] = data;
        int nextRound[] = new int[size / 2];
        Arrays.fill(nextRound, 0x7FFFFFFF);
        int comparedWithMin[] = new int[(int)Math.ceil(Math.log(size) / Math.log(2))];
        Arrays.fill(comparedWithMin, 0x7FFFFFFF);
        int i = 0;
        int round = 0;

        while (true) {
            int small, big;

            if (currentRound.length < 3)
                break;
            if (i >= currentRound.length) {
                i = 0;
                int temp[] = new int[nextRound.length];
                System.arraycopy(nextRound, 0, temp, 0, nextRound.length);
                currentRound = temp;
                if (remainder >= 0 && currentRound.length % 2 != 0)
                    nextRound = new int[currentRound.length / 2 + 1];
                else
                    nextRound = new int[currentRound.length / 2];
                Arrays.fill(nextRound, 0x7FFFFFFF);
                continue;
            }
            else if (i == currentRound.length - 1) {    //currentRound의 사이즈가 홀수
                if (remainder >= 0) {
                    if (remainder > currentRound[i]) {
                        small = currentRound[i];
                        big = remainder;
                    }
                    else {
                        small = remainder;
                        big = currentRound[i];
                    }
                    nextRound[nextRound.length - 1] = small;
                    if (small == data[minIndex])
                        comparedWithMin[round++] = big;
                    remainder = -1;
                    i++;
                }
                else
                    remainder = currentRound[i++];
                continue;
            }

            if (currentRound[i] > currentRound[i + 1]) {
                small = currentRound[i + 1];
                big = currentRound[i];
            }
            else {
                small = currentRound[i];
                big = currentRound[i + 1];
            }
            if (small == data[minIndex])
                comparedWithMin[round++] = big;
            nextRound[i / 2] = small;
            i = i + 2;
        }
        if (currentRound.length == 2) {
            int secondMin, lastMax;

            if (currentRound[0] > currentRound[1]) {
                secondMin = currentRound[1];
                lastMax = currentRound[0];
            }
            else {
                secondMin = currentRound[0];
                lastMax = currentRound[1];
            }
            if (remainder >= 0) {
                if (remainder == data[minIndex])
                    comparedWithMin[round] = secondMin;
                else if (remainder > lastMax)
                    comparedWithMin[round] = lastMax;
                else
                    comparedWithMin[round] = remainder;
            }
            else
                comparedWithMin[round] = lastMax;
        }
        else {
            if (remainder >= 0) {
                if (currentRound[0] > remainder)
                    comparedWithMin[round] = currentRound[0];
                else
                    comparedWithMin[round] = remainder;
            }
        }
        sec = comparedWithMin[findMinimum(comparedWithMin)];
        return sec;
    }

    int findMinimum(int[] array) {
        //배열 array에서 최솟값의 위치를 찾아 반환하는 함수
    }
}

int main(){

	second test;
	return;
	


}
