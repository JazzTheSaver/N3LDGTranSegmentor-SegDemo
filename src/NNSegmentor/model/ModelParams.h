#ifndef SRC_ModelParams_H_
#define SRC_ModelParams_H_
#include "HyperParams.h"

// Each model consists of two parts, building neural graph and defining output losses.
class ModelParams {

public:
	//neural parameters
	Alphabet embeded_words; // words
	LookupTable word_table; // should be initialized outside	
	Alphabet embeded_chars; // chars
	LookupTable char_table; // should be initialized outside	
	Alphabet embeded_chartypes; // chars
	LookupTable chartype_table; // should be initialized outside	
	Alphabet embeded_bichars; // bichars
	LookupTable bichar_table; // should be initialized outside
	Alphabet embeded_actions; // bichars
	LookupTable action_table; // should be initialized outside

	UniParams char_tanh_conv; // hidden
	LSTM1Params char_left_lstm; //left lstm
	LSTM1Params char_right_lstm; //right lstm
	UniParams char_state_hidden;

	LSTM1Params word_lstm;
	UniParams word_state_hidden;

	LSTM1Params action_lstm;
	UniParams action_state_hidden;

	BiParams app_state_represent;
	TriParams sep_state_represent;

	UniParams sep_score;
	UniParams app_score;

	//should be initialized outside
	Alphabet words; // words
	Alphabet chars; // chars
	Alphabet charTypes; // char type



public:
	bool initial(HyperParams& opts) {
		// some model parameters should be initialized outside
		if (words.size() <= 0 || chars.size() <= 0) {
			return false;
		}
		//neural features
		char_tanh_conv.initial(opts.char_hidden_dim, opts.char_represent_dim, true);
		char_left_lstm.initial(opts.char_lstm_dim, opts.char_hidden_dim); //left lstm
		char_right_lstm.initial(opts.char_lstm_dim, opts.char_hidden_dim); //right lstm
		char_state_hidden.initial(opts.char_state_dim, opts.char_feat_dim, true);

		word_lstm.initial(opts.word_lstm_dim, opts.word_dim);
		word_state_hidden.initial(opts.word_state_dim, opts.word_feat_dim, true);
		action_lstm.initial(opts.action_lstm_dim, opts.action_dim);
		action_state_hidden.initial(opts.action_state_dim, opts.action_feat_dim, true);

		app_state_represent.initial(opts.app_dim, opts.char_state_dim, opts.action_state_dim, true);
		sep_state_represent.initial(opts.sep_dim, opts.char_state_dim, opts.word_state_dim, opts.action_state_dim, true);

		sep_score.initial(1, opts.sep_dim, false);
		app_score.initial(1, opts.app_dim, false);

		sep_score.W.val.random(0.01);
		app_score.W.val.random(0.01);
		return true;
	}


	void exportModelParams(ModelUpdate& ada) {
		//neural features
		word_table.exportAdaParams(ada);
		char_table.exportAdaParams(ada);
		chartype_table.exportAdaParams(ada);
		bichar_table.exportAdaParams(ada);
		action_table.exportAdaParams(ada);

		char_tanh_conv.exportAdaParams(ada);
		char_left_lstm.exportAdaParams(ada);
		char_right_lstm.exportAdaParams(ada);
		char_state_hidden.exportAdaParams(ada);

		word_lstm.exportAdaParams(ada);
		word_state_hidden.exportAdaParams(ada);
		action_lstm.exportAdaParams(ada);
		action_state_hidden.exportAdaParams(ada);

		app_state_represent.exportAdaParams(ada);
		sep_state_represent.exportAdaParams(ada);

		sep_score.exportAdaParams(ada);
		app_score.exportAdaParams(ada);

	}


	void saveModel(std::ofstream& os) const {
		embeded_words.write(os);
		word_table.save(os);
		embeded_chars.write(os);
		char_table.save(os);
		embeded_chartypes.write(os);
		chartype_table.save(os);
		embeded_bichars.write(os);
		bichar_table.save(os);
		embeded_actions.write(os);
		action_table.save(os);

		char_tanh_conv.save(os);
		char_left_lstm.save(os);
		char_right_lstm.save(os);
		char_state_hidden.save(os);

		word_lstm.save(os);
		word_state_hidden.save(os);

		action_lstm.save(os);
		action_state_hidden.save(os);

		app_state_represent.save(os);
		sep_state_represent.save(os);

		sep_score.save(os);
		app_score.save(os);

		words.write(os);
		chars.write(os);
		charTypes.write(os);
	}

	void loadModel(std::ifstream& is) {
		embeded_words.read(is);
		word_table.load(is, &embeded_words);
		embeded_chars.read(is);
		char_table.load(is, &embeded_chars);
		embeded_chartypes.read(is);
		chartype_table.load(is, &embeded_chartypes);
		embeded_bichars.read(is);
		bichar_table.load(is, &embeded_bichars);
		embeded_actions.read(is);
		action_table.load(is, &embeded_actions);

		char_tanh_conv.load(is);
		char_left_lstm.load(is);
		char_right_lstm.load(is);
		char_state_hidden.load(is);

		word_lstm.load(is);
		word_state_hidden.load(is);

		action_lstm.load(is);
		action_state_hidden.load(is);

		app_state_represent.load(is);
		sep_state_represent.load(is);

		sep_score.load(is);
		app_score.load(is);

		words.read(is);
		chars.read(is);
		charTypes.read(is);
	}

};

#endif /* SRC_ModelParams_H_ */