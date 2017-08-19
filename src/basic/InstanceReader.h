#ifndef _CONLL_READER_
#define _CONLL_READER_

#include "Reader.h"
#include "N3LDG.h"
#include "Utf.h"
#include <sstream>

using namespace std;
/*
 this class reads conll-format data (10 columns, no srl-info)
 */
class InstanceReader: public Reader {
public:
  InstanceReader() {
  }
  ~InstanceReader() {
  }

  Instance *getNext(bool bFile = true) {
			m_instance.clear();
			string strLine;
			while (1) {
				if (!my_getline(*m_inf, strLine)) {
					break;
				}
				if (!strLine.empty())
					break;
			}
			if (bFile) {
				vector<string> wordInfo;
				split_bychar(strLine, wordInfo, ' ');

				string sentence = "";
				for (int i = 0; i < wordInfo.size(); ++i) {
					sentence = sentence + wordInfo[i];
				}

				vector<string> charInfo;
				getCharactersFromUTF8String(sentence, charInfo);

				m_instance.allocate(wordInfo.size(), charInfo.size());
				for (int i = 0; i < wordInfo.size(); ++i) {
					m_instance.words[i] = wordInfo[i];
				}
				for (int i = 0; i < charInfo.size(); ++i) {
					m_instance.chars[i] = charInfo[i];
				}
			}
			else {
				vector<string> charInfo;
				getCharactersFromUTF8String(strLine, charInfo);
				int charNum = charInfo.size();
				m_instance.allocate(1, charNum);
				m_instance.words[0] = nullkey;
				for(int idx = 0; idx < charNum; idx++) {
					m_instance.chars[idx] = charInfo[idx];
				}
			}

			return &m_instance;
  }
};

#endif

