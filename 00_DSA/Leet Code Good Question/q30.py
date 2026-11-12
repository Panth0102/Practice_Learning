# 30. Substring with Concatenation of All Words

class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        ans = []
        word_len = len(words[0])
        total_len = word_len * len(words)

        for i in range(len(s) - total_len + 1):
            sub = s[i:i + total_len]
            temp = words.copy()

            valid = True

            for j in range(0, total_len, word_len):
                word = sub[j:j + word_len]

                if word in temp:
                    temp.remove(word)
                else:
                    valid = False
                    break

            if valid:
                ans.append(i)

        return ans