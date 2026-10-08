#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

class AnswerGrader {
public:
    static string toLowerCase(const string& str) {
        string lower;
        for (char ch : str)
            lower += tolower(ch);
        return lower;
    }

    static vector<string> tokenize(const string& sentence) {
        vector<string> tokens;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            tokens.push_back(toLowerCase(word));
        }
        return tokens;
    }

    static double wordSimilarity(const string& student, const string& key) {
        vector<string> sWords = tokenize(student);
        vector<string> kWords = tokenize(key);
        unordered_set<string> studentSet(sWords.begin(), sWords.end());
        unordered_set<string> keySet(kWords.begin(), kWords.end());

        int common = 0;
        for (const string& word : keySet)
            if (studentSet.count(word)) common++;

        int total = studentSet.size() + keySet.size() - common;
        if (total == 0) return 0;
        return (double)common / total;
    }

    static void printDPTable(const vector<vector<int>>& dp, const vector<string>& a, const vector<string>& b) {
        cout << "\nDP Table (LCS lengths):\n";
        cout << "      ";
        for (const auto& wordB : b) cout << wordB << " ";
        cout << "\n";

        for (int i = 0; i <= (int)a.size(); ++i) {
            if (i == 0) cout << "  ";
            else cout << a[i - 1] << " ";
            for (int j = 0; j <= (int)b.size(); ++j)
                cout << dp[i][j] << " ";
            cout << "\n";
        }
        cout << endl;
    }

    static int lcs(const vector<string>& a, const vector<string>& b, bool showDP = false) {
        int n = (int)a.size(), m = (int)b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        if (showDP) printDPTable(dp, a, b);

        return dp[n][m];
    }

    static double sentenceSimilarity(const string& student, const string& key, bool showDP = false) {
        vector<string> a = tokenize(student);
        vector<string> b = tokenize(key);
        int lcsLen = lcs(a, b, showDP);
        int maxLen = (int)max(a.size(), b.size());
        if (maxLen == 0) return 0;
        return (double)lcsLen / maxLen;
    }
};

class AnswerKey {
public:
    vector<string> answers;
    vector<vector<string>> questionKeywords;

    AnswerKey(const vector<string>& ans, const vector<vector<string>>& kw)
        : answers(ans), questionKeywords(kw) {}
};

class StudentAnswer {
public:
    vector<string> answers;
    StudentAnswer(const vector<string>& ans) : answers(ans) {}
};

struct EvaluationResult {
    vector<double> questionMarks;
    double totalMarks;
};

class ExamEvaluator {
public:

    static EvaluationResult grade(
        const StudentAnswer& student,
        const AnswerKey& key,
        const vector<int>& mark_allot,
        bool showDP = false
    ) {
        vector<double> scores;
        double total = 0;

        for (int i = 0; i < (int)key.answers.size(); ++i) {
            double wordSim = 0, sentSim = 0, keywordBonus = 0;

            if (i < (int)student.answers.size()) {
                wordSim = AnswerGrader::wordSimilarity(student.answers[i], key.answers[i]);
                bool printDP = showDP && (i >= 3); 
                sentSim = AnswerGrader::sentenceSimilarity(student.answers[i], key.answers[i], printDP);

                vector<string> tokens = AnswerGrader::tokenize(student.answers[i]);
                unordered_set<string> tokenSet(tokens.begin(), tokens.end());

                int kwFound = 0;
                for (const string& kw : key.questionKeywords[i])
                    if (tokenSet.count(kw))
                        kwFound++;

                keywordBonus = 0.1 * kwFound; 
                if (keywordBonus > 0.4) keywordBonus = 0.4; 
            }

            double combined;
            if (i < 3) {
                combined = 0.7 * wordSim + 0.3 * keywordBonus;
            } else {
                combined = 0.5 * wordSim + 0.3 * sentSim + 0.2 * keywordBonus;
            }

            if (combined > 1.0) combined = 1.0;
            if (combined < 0) combined = 0;

            double marks = combined * mark_allot[i];
            scores.push_back(marks);
            total += marks;
        }

        return {scores, total};
    }
};

int main() {
    cout << "📝 DBMS Auto Grader\n-----------------------------\n";

    vector<string> answerKey = {
        "A primary key uniquely identifies each record in a table.",
        "Normalization reduces data redundancy and improves data integrity.",
        "ACID stands for Atomicity, Consistency, Isolation, Durability.",
        "ER Model is a high-level data model that defines data elements and relationships.",
        "Transactions ensure data consistency and follow ACID properties. They can be committed or rolled back.",
        "Indexing improves database performance by allowing faster retrieval of records using keys."
    };

    vector<string> studentAnswers = {
        "Primary key is used to identify each row in a table uniquely.",
        "Normalization helps avoid redundancy and keeps data clean.",
        "ACID means Atomic, Consistent, Isolated, and Durable.",
        "ER model defines entities and their relationships using diagrams.",
        "Transactions maintain consistency and follow ACID rules. They can be saved or canceled.",
        "Indexing helps in fast searching of data using keys."
    };

    vector<int> mark_allot = {5, 5, 5, 15, 15, 15};

    vector<vector<string>> keywords = {
        {"primary","key"},
        {"normalization"},
        {"acid"},
        {"er","model"},
        {"transaction","acid"},
        {"indexing","performance"}
    };

    AnswerKey key(answerKey, keywords);
    StudentAnswer student(studentAnswers);

    EvaluationResult result = ExamEvaluator::grade(student, key, mark_allot, true);

    cout << "\n📊 Marks Breakdown per Question:\n";
    cout << "+----------+----------------+--------+\n";
    cout << "|   Q.No   |   Description  | Marks  |\n";
    cout << "+----------+----------------+--------+\n";

    for (int i = 0; i < (int)result.questionMarks.size(); ++i) {
        string label = (i < 3) ? "Short Ans" : "Long Ans ";
        printf("|   Q%-2d    |  %-12s | %6.2f |\n", i + 1, label.c_str(), result.questionMarks[i]);
    }

    cout << "+----------+----------------+--------+\n";
    printf("|  Total   |                | %6.2f |\n", result.totalMarks*3);
    cout << "+----------+----------------+--------+\n";

    return 0;
}
