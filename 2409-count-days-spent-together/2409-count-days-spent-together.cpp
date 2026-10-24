class Solution {
public:
int f(string& date){
    int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int month = (date[0] - '0') * 10 + (date[1] - '0');
    int day = (date[3] - '0') * 10 + (date[4] - '0');
    return days[month - 1] + day;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string arrive = max(arriveAlice, arriveBob);
        string leave = min(leaveAlice, leaveBob);
        if(arrive > leave)return 0;
        return f(leave) - f(arrive) + 1;
    }
};