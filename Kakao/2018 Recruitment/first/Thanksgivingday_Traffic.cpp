#include <string>
#include <vector>
#include <cmath>
using namespace std;

const double Eps = 0.0001;

vector<double> GetLogEnd(vector<string>& str);
vector<double> GetLogStart(vector<double> log, vector<double> time);
vector<double> GetHandleTime(vector<string> str);
bool isInside(double s, double e, double log_s, double log_e);
bool compare(double a, double b);

int solution(vector<string> lines)
{
    int answer = 0, max = -1, cnt = 0, i, j, res;
    double st_s, st_e, s, e;
    bool flag = false;
    vector<double> log_start, log_end, handle_time;
    log_end = GetLogEnd(lines);
    handle_time = GetHandleTime(lines);
    log_start = GetLogStart(log_end, handle_time);

    for (i = 0; i < log_start.size(); i++) {
        cnt = 0;
        st_s = log_start[i];
        st_e = log_start[i] + (double)0.999;
        for (j = 0; j < log_start.size(); j++) {
            s = log_start[j], e = log_end[j];
            if (isInside(s, e, st_s, st_e)) cnt++;
        }
        max = cnt > max ? cnt : max;

        cnt = 0;
        st_e = log_start[i];
        st_s = log_start[i] - (double)0.999;
        for (j = 0; j < log_start.size(); j++) {
            s = log_start[j], e = log_end[j];
            if (isInside(s, e, st_s, st_e)) cnt++;
        }
        max = cnt > max ? cnt : max;

        cnt = 0;
        st_s = log_end[i];
        st_e = log_end[i] + (double)0.999;
        for (j = 0; j < log_start.size(); j++) {
            s = log_start[j], e = log_end[j];
            if (isInside(s, e, st_s, st_e)) cnt++;
        }
        max = cnt > max ? cnt : max;

        cnt = 0;
        st_e = log_end[i];
        st_s = log_end[i] - (double)0.999;
        for (j = 0; j < log_start.size(); j++) {
            s = log_start[j], e = log_end[j];
            if (isInside(s, e, st_s, st_e)) cnt++;
        }
        max = cnt > max ? cnt : max;
    }

    answer = max;
    return answer;
}

bool compare(double a, double b)
{
    if (a < b) return true;
    else if (fabs(a - b) < Eps) return true;
    else return false;
}

bool isInside(double s, double e, double st_s, double st_e)
{
    if ((compare(st_s, s) && compare(s, st_e)) || (compare(st_s, e) && compare(e, st_e))) return true;
    else if (compare(s, st_s) && compare(st_e, e)) return true;

    return false;
}

vector<double> GetLogEnd(vector<string>& str)
{
    int i;
    double h, m, s;
    string temp;
    vector<double> res;

    for (i = 0; i < str.size(); i++) {
        str[i].erase(0, 11);
        temp = str[i].substr(0, 2);
        h = stod(temp);
        temp = str[i].substr(3, 2);
        m = stod(temp);
        temp = str[i].substr(6, 6);
        s = stod(temp);
        str[i].erase(0, 13);
        res.push_back(h * 3600.0 + m * 60.0 + s);
    }

    return res;
}

vector<double> GetHandleTime(vector<string> str)
{
    int i;
    vector<double> res;
    string sub;

    for (i = 0; i < str.size(); i++) {
        sub = str[i].substr(0, str[i].size() - 1);
        res.push_back(stod(sub));
    }

    return res;
}

vector<double> GetLogStart(vector<double> log, vector<double> time)
{
    vector<double> res;
    int i;

    for (i = 0; i < log.size(); i++) {
        res.push_back(log[i] - time[i] + 0.001);
    }

    return res;
}