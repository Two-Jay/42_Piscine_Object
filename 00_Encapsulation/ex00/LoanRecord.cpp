#include "Bank.hpp"
#include <string>

int Bank::LoanRecord::getId() const {
    return _id;
}

int Bank::LoanRecord::getValue() const {
    return _value;
}

int Bank::LoanRecord::getInterest() const {
    return _interest;
}

int Bank::LoanRecord::getDurationMonths() const {
    return _duration_months;
}

time_t Bank::LoanRecord::getTime() const {
    return _time;
}

void Bank::addLoanRecordHistory(LoanRecord &lr) {
    std::map<int, std::vector<LoanRecord> >::iterator it = _loanRecords.find(lr._id);
    if (it == _loanRecords.end()) {
        std::vector<LoanRecord> loanRecords = std::vector<LoanRecord>();
        loanRecords.push_back(lr);
        _loanRecords.insert(std::pair<int, std::vector<LoanRecord> >(lr._id, loanRecords));
    } else {
        it->second.push_back(lr);
    }
}

Bank::LoanRecord Bank::createNewLoanRecord(int accountId, int value, int duration) {
    LoanRecord loanRecord = LoanRecord();
    loanRecord._id = accountId;
    loanRecord._value = value;
    loanRecord._interest = value * _interestRate;
    loanRecord._duration_months = duration;
    loanRecord._time = time(NULL);
    return (loanRecord);
}

std::string getTimeFormatString(time_t time) {
    struct tm *timeinfo;
    char buffer[80];
    timeinfo = localtime(&time);
    strftime(buffer, 80, "%Y-%m-%d", timeinfo);
    return (std::string(buffer));
}

std::ostream &operator<<(std::ostream &p_os, const Bank::LoanRecord &p_loanRecord) {
    p_os << "| -- Loan record - ID. " << p_loanRecord.getId() << " -------------- " << std::endl;
    p_os << "| Value : " << p_loanRecord.getValue() << std::endl;
    p_os << "| Interest : " << p_loanRecord.getInterest() << std::endl;
    p_os << "| Duration : " << p_loanRecord.getDurationMonths() << " months from " << getTimeFormatString(p_loanRecord.getTime()) << std::endl;
    p_os << "| ------------------------------------- " << std::endl;
    return (p_os);
}

