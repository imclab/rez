#include "lolTranslator.h"
#include <iostream>

namespace translate {

LolTranslator::LolTranslator()
{
	m_words.insert(word_map::value_type("hello", "oh hai"));
	m_words.insert(word_map::value_type("have", "haz"));
	m_words.insert(word_map::value_type("cheeseburger", "cheezburger"));
}


// changed in 2.0.1
// It just wasn't lolspeak enough
// ABI hasn't changed, so this is a patch update
std::string LolTranslator::getSentence(const std::string& sentence) const
{
	std::string s = Translator::getSentence(sentence);

	if(s.find_last_of('!') == s.size()-1)
		s += "! LOLZ!";

	return s;
}


std::string LolTranslator::getWord(const std::string& word) const
{
	word_map::const_iterator it = m_words.find(word);
	return (it == m_words.end())? word : it->second;
}

}
