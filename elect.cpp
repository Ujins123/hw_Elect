#include <iostream>
#include <fstream>
using namespace std;

// 추상클래스
class ElectricityBase {
public:
    virtual void displayInfo() const = 0; // 순수 가상 함수: 전기 정보 출력
    virtual ~ElectricityBase() {}        // 가상 소멸자
};

// 전기 관리 클래스
class ElectricityManager : public ElectricityBase {
private:
    int lastMonthUsage;   // 지난달 전기 사용량
    int currentDay;       // 현재 날짜
    static const int AVERAGE_USAGE = 10600; // 1인 가구 평균 사용량

public:
    ElectricityManager(int usage, int day) : lastMonthUsage(usage), currentDay(day) {}

    // 이번 달 예상 사용량 계산
    int predictThisMonth() const {
        double dailyUsage = static_cast<double>(lastMonthUsage) / 30.0; // 하루 평균 사용량 계산
        return static_cast<int>(dailyUsage * currentDay); // 현재 날짜까지의 사용량을 기반으로 예측
    }

    // 정보 출력 (다형성 활용)
    void displayInfo() const override {
        cout << "지난달 전기 사용량: " << lastMonthUsage << " kWh\n";
        cout << "현재 날짜: " << currentDay << "일\n";
        cout << "이번 달 예상 사용량: " << predictThisMonth() << " kWh\n";
        cout << "1인 가구 평균 사용량: " << AVERAGE_USAGE << " kWh\n";
        if (lastMonthUsage > AVERAGE_USAGE)
            cout << "Tip: 사용량이 많습니다. 에너지 절약을 고려하세요!\n";
        else
            cout << "Tip: 사용량이 평균 이하입니다. 잘 유지하세요!\n";
    }
};

int main() {
    // 사용자 입력
    int lastMonthUsage, currentDay;
    cout << "지난달 전기 사용량(kWh)을 입력하세요: ";
    cin >> lastMonthUsage;
    cout << "현재 날짜(1~30)를 입력하세요: ";
    cin >> currentDay;

    // 전기 관리 객체 생성
    ElectricityManager user(lastMonthUsage, currentDay);

    // 결과 출력
    cout << "\n----- 전기 사용량 보고서 -----\n";
    user.displayInfo();

    // 예외 없이 정상 종료
    return 0;
}
