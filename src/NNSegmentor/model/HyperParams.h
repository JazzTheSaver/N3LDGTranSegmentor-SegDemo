#ifndef SRC_HyperParams_H_
#define SRC_HyperParams_H_

#include "N3LDG.h"
#include "Options.h"

using namespace nr;
using namespace std;

struct HyperParams {
	//required
	int beam;
	int batch;
	int maxlength;
	int action_num;
	dtype delta;


	dtype nnRegular; // for optimization
	dtype adaAlpha;  // for optimization
	dtype adaEps; // for optimization
	dtype dropProb;

	int char_dim;
	int chartype_dim;
	int bichar_dim;
	int char_represent_dim;
	int char_hidden_dim;
	int char_lstm_dim;
	int char_feat_dim;
	int char_state_dim;
	bool char_tune;
	bool bichar_tune;

	int word_dim;
	int word_lstm_dim;
	int word_feat_dim;
	int word_state_dim;
	bool word_tune;

	int action_dim;
	int action_lstm_dim;
	int action_feat_dim;
	int action_state_dim;

	int app_dim;
	int sep_dim;

public:
	HyperParams() {
		maxlength = max_sentence_clength + 1;
		bAssigned = false;
	}

public:
	void setRequared(Options& opt) {
		//please specify dictionary outside
		//please sepcify char_dim, word_dim and action_dim outside.
		beam = opt.beam;
		batch = opt.batchSize;
		delta = opt.delta;
		bAssigned = true;

		nnRegular = opt.regParameter;
		adaAlpha = opt.adaAlpha;
		adaEps = opt.adaEps;
		dropProb = opt.dropProb;

		char_dim = opt.charEmbSize;
		bichar_dim = opt.bicharEmbSize;
		chartype_dim = opt.charTypeEmbSize;
		char_represent_dim = char_dim + bichar_dim + chartype_dim;
		char_hidden_dim = opt.charHiddenSize;
		char_lstm_dim = opt.charRNNHiddenSize;
		char_feat_dim = 12 * char_lstm_dim;
		char_state_dim = opt.charStateSize;
		char_tune = opt.charEmbFineTune;
		bichar_tune = opt.bicharEmbFineTune;

		word_dim = opt.wordEmbSize;
		word_lstm_dim = opt.wordRNNHiddenSize;
		word_feat_dim = 2 * word_lstm_dim;
		word_state_dim = opt.wordStateSize;
		word_tune = opt.wordEmbFineTune;

		action_dim = opt.actionEmbSize;
		action_lstm_dim = opt.actionRNNHiddenSize;
		action_feat_dim = 2 * action_lstm_dim;
		action_state_dim = opt.actionStateSize;

		app_dim = opt.appHiddenSize;
		sep_dim = opt.sepHiddenSize;
	}

	void clear() {
		bAssigned = false;
	}

	bool bValid() {
		return bAssigned;
	}


public:

	void print() {
		std::cout << "======= Hyper Params =======" << std::endl;
		std::cout << "beam = "<< beam << std::endl;
		std::cout << "maxlength = "<< maxlength << std::endl;
		std::cout << "action_num = " << action_num << std::endl;
		std::cout << "delta = " << delta << std::endl;


		std::cout << "nnRegular = " << nnRegular << std::endl;
		std::cout << "adaAlpha = "<< adaAlpha << std::endl;
		std::cout << "adaEps = "<< adaEps << std::endl;
		std::cout << "dropProb = " << dropProb << std::endl;

		std::cout << "char_dim = "<< char_dim << std::endl;
		std::cout << "chartype_dim = " << chartype_dim << std::endl;
		std::cout << "bichar_dim = " << bichar_dim << std::endl;
		std::cout << "char_represent_dim = "<< char_represent_dim << std::endl;
		std::cout << "char_hidden_dim = " << char_hidden_dim << std::endl;
		std::cout << "char_lstm_dim = " << char_lstm_dim << std::endl;
		std::cout << "char_feat_dim = " << char_feat_dim << std::endl;
		std::cout << "char_state_dim = " << char_state_dim << std::endl;
		std::cout << "char_tune = " << char_tune << std::endl;
		std::cout << "bichar_tune = " << bichar_tune << std::endl;

		std::cout << "word_dim = " << word_dim << std::endl;
		std::cout << "word_lstm_dim = " << word_lstm_dim << std::endl;
		std::cout << "word_feat_dim = " << word_feat_dim << std::endl;
		std::cout << "word_state_dim = "<< word_state_dim << std::endl;
		std::cout << "word_tune = " << word_tune << std::endl;

		std::cout << "action_dim = " << action_dim << std::endl;
		std::cout << "action_lstm_dim = " << action_lstm_dim << std::endl;
		std::cout << "action_feat_dim = " << action_feat_dim << std::endl;
		std::cout << "action_state_dim = " << action_state_dim << std::endl;

		std::cout << "app_dim = " << app_dim << std::endl;
		std::cout << "sep_dim = " << sep_dim << std::endl;
		std::cout << "=======================" << std::endl;
	}

	void saveModel(std::ofstream& os)const {
		os << beam << std::endl;
		os << maxlength << std::endl;
		os << action_num << std::endl;
		os << delta << std::endl;


		os << nnRegular << std::endl;
		os << adaAlpha << std::endl;
		os << adaEps << std::endl;
		os << dropProb << std::endl;

		os << char_dim << std::endl;
		os << chartype_dim << std::endl;
		os << bichar_dim << std::endl;
		os << char_represent_dim << std::endl;
		os << char_hidden_dim << std::endl;
		os << char_lstm_dim << std::endl;
		os << char_feat_dim << std::endl;
		os << char_state_dim << std::endl;
		os << char_tune << std::endl;
		os << bichar_tune << std::endl;

		os << word_dim << std::endl;
		os << word_lstm_dim << std::endl;
		os << word_feat_dim << std::endl;
		os << word_state_dim << std::endl;
		os << word_tune << std::endl;

		os << action_dim << std::endl;
		os << action_lstm_dim << std::endl;
		os << action_feat_dim << std::endl;
		os << action_state_dim << std::endl;

		os << app_dim << std::endl;
		os << sep_dim << std::endl;
	}

	void loadModel(std::ifstream& is){
		is >> beam;
		is >> maxlength;
		is >> action_num;
		is >> delta;


		is >> nnRegular; 
		is >> adaAlpha; 
		is >> adaEps;
		is >> dropProb;

		is >> char_dim;
		is >> chartype_dim;
		is >> bichar_dim;
		is >> char_represent_dim;
		is >> char_hidden_dim;
		is >> char_lstm_dim;
		is >> char_feat_dim;
		is >> char_state_dim;
		is >> char_tune;
		is >> bichar_tune;

		is >> word_dim;
		is >> word_lstm_dim;
		is >> word_feat_dim;
		is >> word_state_dim;
		is >> word_tune;

		is >> action_dim;
		is >> action_lstm_dim;
		is >> action_feat_dim;
		is >> action_state_dim;

		is >> app_dim;
		is >> sep_dim;
	}

private:
	bool bAssigned;
};


#endif /* SRC_HyperParams_H_ */