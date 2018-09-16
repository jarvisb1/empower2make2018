#include "icons.h"

#include <U8glib.h>

const uint8_t Previews[10][128] U8G_PROGMEM = {
  {160,234,174,10,240,255,255,15,160,251,191,10,208,255,255,13,170,238,238,174,255,255,255,255,186,251,255,171,253,255,255,223,234,224,14,174,255,240,15,255,251,240,15,191,255,240,15,255,238,238,174,238,255,255,255,255,251,251,187,255,255,255,255,255,14,160,10,224,15,240,15,240,15,176,11,240,15,240,15,240,238,0,0,174,255,0,0,255,251,0,0,187,255,0,0,255,170,14,224,170,255,15,240,255,186,15,240,171,253,15,240,223,160,238,174,10,240,255,255,15,160,251,187,10,208,255,255,13},
  {0,224,14,0,0,240,15,0,0,240,15,0,0,240,15,0,0,174,170,0,0,95,245,0,0,171,186,0,0,223,253,0,0,174,234,0,0,95,245,0,0,175,250,0,0,223,253,0,160,174,234,10,240,95,245,15,176,175,250,11,240,223,253,15,224,174,234,14,240,255,255,15,240,191,251,15,240,255,255,15,224,175,234,15,240,95,245,15,240,175,250,15,240,223,253,15,234,174,234,174,255,95,245,255,251,175,250,191,255,223,253,255,239,174,238,238,255,255,255,255,255,191,251,255,255,255,255,255},
  {160,170,170,10,80,117,127,5,160,170,170,10,80,221,221,5,170,170,170,170,85,247,247,87,170,170,170,170,213,221,221,93,170,160,10,170,117,240,15,127,170,160,10,170,221,208,13,221,170,170,170,170,247,247,87,247,170,170,170,170,221,221,221,221,170,10,160,170,255,15,240,127,170,10,160,170,221,13,208,221,170,0,0,170,247,0,0,87,170,0,0,170,221,0,0,221,170,160,10,170,117,112,5,85,170,160,10,170,213,208,13,93,160,170,170,10,80,247,87,5,160,170,170,10,80,221,221,5},
  {0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,10,0,0,240,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0},
  {0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,14,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,14,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,10,0,0,240,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0},
  {174,174,14,0,255,255,15,0,175,175,15,0,255,255,15,0,175,175,15,0,255,255,15,0,175,175,15,0,255,255,15,0,174,174,14,14,255,255,15,15,175,175,15,15,255,255,15,15,175,175,15,15,255,255,15,15,175,175,15,15,255,255,15,15,238,238,238,14,255,255,255,15,255,255,255,15,255,255,255,15,239,239,239,15,255,255,255,15,255,255,255,15,255,255,255,15,238,238,254,10,255,255,255,15,255,255,255,10,255,255,255,15,224,239,175,0,240,255,255,0,240,255,175,0,240,255,255,0},
  {160,238,234,10,240,255,255,15,176,187,187,11,240,255,255,15,224,238,238,14,240,255,255,15,240,251,255,11,240,255,255,79,0,32,226,10,80,85,245,31,0,168,250,11,64,85,245,79,0,174,238,14,80,255,255,31,0,187,251,11,80,255,255,79,0,238,238,0,16,255,255,5,0,251,255,0,64,255,255,5,0,0,0,0,0,85,85,0,0,128,0,0,64,84,69,0,0,238,0,0,0,255,0,0,0,191,0,0,0,255,4,0,0,174,0,0,0,255,0,0,0,187,0,0,0,255,0,0},
  {0,238,238,0,0,255,255,0,0,255,255,0,0,255,255,0,224,255,255,14,240,255,255,15,240,255,255,11,240,255,255,15,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,251,255,255,255,255,255,255,255,224,255,255,14,240,255,255,15,176,255,255,15,240,255,255,15,0,238,238,0,0,255,255,0,0,251,255,0,0,255,255,0},
  {0,0,0,0,0,16,21,0,0,0,0,0,0,68,68,0,0,224,239,0,16,245,255,5,0,240,255,0,64,245,255,4,0,254,254,14,80,255,255,31,0,251,255,11,84,255,255,79,224,242,242,226,241,245,245,245,240,250,250,250,244,245,245,245,32,254,254,14,85,255,255,95,128,251,251,15,84,255,255,79,224,238,239,0,241,255,255,5,240,251,255,0,244,255,255,69,240,46,0,0,240,95,85,1,240,139,8,0,244,95,85,4,239,0,0,0,255,81,1,0,255,0,0,0,255,68,68,0},
  {42,42,10,0,95,95,15,0,171,171,11,0,95,95,15,0,174,174,14,0,95,95,15,0,171,171,11,0,95,95,15,0,42,42,10,10,95,95,15,15,171,171,11,11,95,95,15,15,174,174,14,14,95,95,15,15,171,171,11,11,95,95,15,15,234,234,234,10,255,255,255,15,187,187,187,11,255,255,255,15,238,174,238,14,255,255,255,15,187,187,187,11,255,255,255,15,234,234,234,10,255,255,255,5,187,187,187,10,255,255,255,5,160,238,174,0,240,255,95,0,176,187,171,0,240,255,95,0}
};

// const uint8_t PROGMEM img_smile[8][8][3] = {
//   {{0,0,0},{148,144,89},{199,192,94},{240,230,100},{240,230,100},{199,192,94},{148,144,89},{0,0,0}},
//   {{148,144,89},{199,192,94},{240,230,100},{240,230,100},{240,230,100},{240,230,100},{199,192,94},{148,144,89}},
//   {{199,192,94},{240,230,100},{0,0,0},{240,230,100},{240,230,100},{0,0,0},{240,230,100},{199,192,94}},
//   {{240,230,100},{240,230,100},{199,192,94},{240,230,100},{240,230,100},{199,192,94},{240,230,100},{240,230,100}},
//   {{240,230,100},{0,0,0},{0,0,0},{199,192,94},{199,192,94},{0,0,0},{0,0,0},{240,230,100}},
//   {{199,192,94},{240,230,100},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{240,230,100},{199,192,94}},
//   {{148,144,89},{199,192,94},{240,230,100},{0,0,0},{0,0,0},{240,230,100},{199,192,94},{148,144,89}},
//   {{0,0,0},{148,144,89},{199,192,94},{240,230,100},{240,230,100},{199,192,94},{148,144,89},{0,0,0}},
// };

// const uint8_t PROGMEM img_A_N_G_R_Y[8][8][3] = {
//   {{0,0,0},{190,34,34},{220,58,58},{227,97,97},{227,97,97},{220,58,58},{190,34,34},{0,0,0}},
//   {{190,34,34},{220,58,58},{227,97,97},{227,97,97},{227,97,97},{227,97,97},{220,58,58},{190,34,34}},
//   {{220,58,58},{227,97,97},{0,0,0},{227,97,97},{227,97,97},{0,0,0},{227,97,97},{220,58,58}},
//   {{227,97,97},{227,97,97},{220,58,58},{227,97,97},{227,97,97},{220,58,58},{227,97,97},{227,97,97}},
//   {{227,97,97},{227,97,97},{227,97,97},{0,0,0},{0,0,0},{227,97,97},{227,97,97},{227,97,97}},
//   {{220,58,58},{227,97,97},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{227,97,97},{220,58,58}},
//   {{190,34,34},{220,58,58},{0,0,0},{220,58,58},{220,58,58},{0,0,0},{220,58,58},{190,34,34}},
//   {{0,0,0},{190,34,34},{220,58,58},{227,97,97},{227,97,97},{220,58,58},{190,34,34},{0,0,0}},
// };

const uint8_t PROGMEM img_attention[8][8][3] = {
  {{19,19,19},{25,25,25},{31,31,31},{110,220,220},{116,205,205},{31,31,31},{25,25,25},{19,19,19}},
  {{23,23,23},{30,30,30},{36,36,36},{110,220,220},{116,205,205},{36,36,36},{30,30,30},{23,23,23}},
  {{25,25,25},{33,33,33},{40,40,40},{110,220,220},{116,205,205},{40,40,40},{33,33,33},{25,25,25}},
  {{26,26,26},{34,34,34},{41,41,41},{110,220,220},{116,205,205},{41,41,41},{34,34,34},{26,26,26}},
  {{25,25,25},{33,33,33},{40,40,40},{116,205,205},{111,188,188},{40,40,40},{33,33,33},{25,25,25}},
  {{23,23,23},{30,30,30},{36,36,36},{43,43,43},{43,43,43},{36,36,36},{30,30,30},{23,23,23}},
  {{21,21,21},{27,27,27},{33,33,33},{110,220,220},{116,205,205},{33,33,33},{27,27,27},{21,21,21}},
  {{17,17,17},{22,22,22},{27,27,27},{116,205,205},{111,188,188},{27,27,27},{22,22,22},{17,17,17}},
};

const uint8_t PROGMEM img_question[8][8][3] = {
  {{42,42,42},{205,190,94},{220,205,110},{220,205,110},{220,205,110},{220,205,110},{205,190,94},{48,48,48}},
  {{48,48,48},{243,228,131},{243,228,131},{243,228,131},{243,228,131},{243,228,131},{220,205,110},{54,54,54}},
  {{49,49,49},{63,63,63},{76,76,76},{83,83,83},{84,84,84},{243,228,131},{220,205,110},{56,56,56}},
  {{49,49,49},{64,64,64},{220,205,110},{205,190,94},{205,190,94},{243,228,131},{220,205,110},{55,55,55}},
  {{46,46,46},{59,59,59},{220,205,110},{243,228,131},{243,228,131},{243,228,131},{63,63,63},{49,49,49}},
  {{40,40,40},{51,51,51},{62,62,62},{67,67,67},{66,66,66},{61,61,61},{53,53,53},{41,41,41}},
  {{34,34,34},{44,44,44},{243,228,131},{220,205,110},{54,54,54},{50,50,50},{43,43,43},{33,33,33}},
  {{26,26,26},{33,33,33},{220,205,110},{205,190,94},{41,41,41},{37,37,37},{31,31,31},{24,24,24}},
};

const uint8_t PROGMEM img_msg[8][8][3] = {
  {{33,33,33},{43,43,43},{52,52,52},{58,58,58},{59,59,59},{57,57,57},{50,50,50},{40,40,40}},
  {{44,44,44},{57,57,57},{68,68,68},{215,215,220},{250,250,255},{215,215,220},{63,63,63},{51,51,51}},
  {{53,53,53},{68,68,68},{215,215,220},{250,250,255},{250,250,255},{250,250,255},{215,215,220},{59,59,59}},
  {{59,59,59},{215,215,220},{40,65,255},{250,250,255},{40,65,255},{250,250,255},{40,65,255},{215,215,220}},
  {{60,60,60},{77,77,77},{200,205,244},{250,250,255},{200,205,244},{250,250,255},{215,215,220},{60,60,60}},
  {{59,59,59},{215,215,220},{215,215,220},{215,215,220},{250,250,255},{215,215,220},{68,68,68},{54,54,54}},
  {{53,53,53},{250,250,255},{215,215,220},{75,75,75},{73,73,73},{67,67,67},{57,57,57},{44,44,44}},
  {{250,250,255},{215,215,220},{59,59,59},{60,60,60},{58,58,58},{53,53,53},{44,44,44},{34,34,34}},
};

const uint8_t PROGMEM img_warning[8][8][3] = {
  {{0,0,0},{0,0,0},{0,0,0},{255,235,0},{255,235,0},{0,0,0},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{200,190,35},{225,5,5},{225,5,5},{200,190,35},{0,0,0},{0,0,0}},
  {{0,0,0},{0,0,0},{255,235,0},{225,5,5},{225,5,5},{255,235,0},{0,0,0},{0,0,0}},
  {{0,0,0},{200,190,35},{255,235,0},{225,5,5},{225,5,5},{255,235,0},{200,190,35},{0,0,0}},
  {{0,0,0},{255,235,0},{255,235,0},{200,190,35},{200,190,35},{255,235,0},{255,235,0},{0,0,0}},
  {{0,0,0},{255,235,0},{255,235,0},{225,5,5},{225,5,5},{255,235,0},{255,235,0},{0,0,0}},
  {{200,190,35},{255,235,0},{255,235,0},{225,5,5},{225,5,5},{255,235,0},{255,235,0},{200,190,35}},
  {{255,235,0},{255,235,0},{255,235,0},{200,190,35},{200,190,35},{255,235,0},{255,235,0},{255,235,0}},
};

// const uint8_t PROGMEM img_warning_off[8][8][3] = {
//   {{0,0,0},{0,0,0},{0,0,0},{128,118,0},{128,118,0},{0,0,0},{0,0,0},{0,0,0}},
//   {{0,0,0},{0,0,0},{100,95,18},{0,0,0},{0,0,0},{100,95,18},{0,0,0},{0,0,0}},
//   {{0,0,0},{0,0,0},{128,118,0},{0,0,0},{0,0,0},{128,118,0},{0,0,0},{0,0,0}},
//   {{0,0,0},{100,95,18},{128,118,0},{0,0,0},{0,0,0},{128,118,0},{100,95,18},{0,0,0}},
//   {{0,0,0},{128,118,0},{128,118,0},{100,95,18},{100,95,18},{128,118,0},{128,118,0},{0,0,0}},
//   {{0,0,0},{128,118,0},{128,118,0},{0,0,0},{0,0,0},{128,118,0},{128,118,0},{0,0,0}},
//   {{100,95,18},{128,118,0},{128,118,0},{0,0,0},{0,0,0},{128,118,0},{128,118,0},{100,95,18}},
//   {{128,118,0},{128,118,0},{128,118,0},{100,95,18},{100,95,18},{128,118,0},{128,118,0},{128,118,0}},
// };

const uint8_t PROGMEM img_excited[8][8][3] = {
  {{19,19,19},{25,25,25},{31,31,31},{110,220,110},{116,205,116},{31,31,31},{25,25,25},{19,19,19}},
  {{23,23,23},{30,30,30},{36,36,36},{110,220,110},{116,205,116},{36,36,36},{30,30,30},{23,23,23}},
  {{25,25,25},{33,33,33},{40,40,40},{110,220,110},{116,205,116},{40,40,40},{33,33,33},{25,25,25}},
  {{26,26,26},{34,34,34},{41,41,41},{110,220,110},{116,205,116},{41,41,41},{34,34,34},{26,26,26}},
  {{25,25,25},{33,33,33},{40,40,40},{116,205,116},{111,188,111},{40,40,40},{33,33,33},{25,25,25}},
  {{23,23,23},{30,30,30},{36,36,36},{43,43,43},{43,43,43},{36,36,36},{30,30,30},{23,23,23}},
  {{21,21,21},{27,27,27},{33,33,33},{110,220,110},{116,205,116},{33,33,33},{27,27,27},{21,21,21}},
  {{17,17,17},{22,22,22},{27,27,27},{116,205,116},{111,188,111},{27,27,27},{22,22,22},{17,17,17}},
};

const uint8_t PROGMEM img_hand[8][8][3] = {
  {{206,251,183},{70,183,10},{206,251,183},{70,183,10},{206,251,183},{0,0,0},{0,0,0},{0,0,0}},
  {{206,251,183},{70,183,10},{206,251,183},{70,183,10},{206,251,183},{0,0,0},{0,0,0},{0,0,0}},
  {{206,251,183},{70,183,10},{206,251,183},{70,183,10},{206,251,183},{0,0,0},{206,251,183},{0,0,0}},
  {{206,251,183},{70,183,10},{206,251,183},{70,183,10},{206,251,183},{0,0,0},{206,251,183},{0,0,0}},
  {{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{0,0,0}},
  {{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{0,0,0}},
  {{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{70,183,10},{0,0,0}},
  {{0,0,0},{206,251,183},{206,251,183},{206,251,183},{206,251,183},{70,183,10},{0,0,0},{0,0,0}},
};

const uint8_t PROGMEM img_stop_hand[8][8][3] = {
  {{251,183,183},{183,10,10},{251,183,183},{183,10,10},{251,183,183},{0,0,0},{0,0,0},{0,0,0}},
  {{251,183,183},{183,10,10},{251,183,183},{183,10,10},{251,183,183},{0,0,0},{0,0,0},{0,0,0}},
  {{251,183,183},{183,10,10},{251,183,183},{183,10,10},{251,183,183},{0,0,0},{251,183,183},{0,0,0}},
  {{251,183,183},{183,10,10},{251,183,183},{183,10,10},{251,183,183},{0,0,0},{251,183,183},{0,0,0}},
  {{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{0,0,0}},
  {{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{0,0,0}},
  {{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{183,10,10},{0,0,0}},
  {{0,0,0},{251,183,183},{251,183,183},{251,183,183},{251,183,183},{183,10,10},{0,0,0},{0,0,0}},
};

const uint8_t PROGMEM img_sun[8][8][3] = {
  {{36,30,10},{36,30,10},{255,230,90},{255,230,90},{255,230,90},{255,220,35},{36,30,10},{36,30,10}},
  {{36,30,10},{255,220,35},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,220,35},{36,30,10}},
  {{255,220,35},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,220,35}},
  {{255,230,90},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,230,90}},
  {{255,230,90},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,230,90}},
  {{255,220,35},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,220,35}},
  {{36,30,10},{255,220,35},{255,255,255},{255,255,255},{255,255,255},{255,255,255},{255,220,35},{36,30,10}},
  {{36,30,10},{36,30,10},{255,220,35},{255,230,90},{255,230,90},{255,220,35},{36,30,10},{36,30,10}},
};

// TODO map correct preview
const auto AlertImage = bitmap::Image24P((const uint8_t*)img_warning, 8, 8);
const auto AlertPreview = bitmap::ImageBitP((const uint8_t*)&Previews[0], 32, 32);
const Icon AlertIcon { AlertImage, AlertPreview };

// TODO map correct preview
const auto QuestionImage = bitmap::Image24P((const uint8_t*)img_question, 8, 8);
const auto QuestionPreview = bitmap::ImageBitP((const uint8_t*)&Previews[1], 32, 32);
const Icon QuestionIcon { QuestionImage, QuestionPreview };

// TODO map correct preview
const auto LightImage = bitmap::Image24P((const uint8_t*)img_sun, 8, 8);
const auto LightPreview = bitmap::ImageBitP((const uint8_t*)&Previews[2], 32, 32);
const Icon LightIcon { LightImage, LightPreview };

const auto EmptyImageOrPreview = bitmap::ImageZero(32, 32);
const Icon EmptyIcon { EmptyImageOrPreview, EmptyImageOrPreview };
