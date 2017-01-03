#ifndef musicFUNCTIONS
#define musicFUNCTIONS

	float BPM = 187, delayTime = 160.4278;
	float quart = delayTime * .2; //In centiseconds
	float eighth = delayTime * .1;
	float half = delayTime * .4;
	float halfDot = delayTime * .6;
	float quartDot = delayTime * .3;
	float sixteenth = delayTime * .05;

#define A4__ 440.000
#define C5__ 523.251
#define D5__ 587.330
#define E5__ 659.255
#define G5__ 783.991
#define G4__ 391.995
#define A5__ 880.000
#define F4__ 349.228
#define B4__ 493.883

//Array format: {Frequency in hertz, length of note in centiseconds}
// intro, beforeRepeat, 1, rest, beforeRepeat, 2, rest, beforeRepeat,

unsigned float intro[71][2] = { //count 0 -> count 70, offset 0}

		{0, sixteenth}, //count = 0
		{D5__, sixteenth}, //count = 1
		{D5__, eighth}, //count = 2
		{D5__, eighth}, //count = 3
		////////////////
		{D5__, eighth}, //count = 4
		{D5__, eighth}, //count = 5
		{D5__, eighth}, //count = 6
		{D5__, eighth}, //count = 7
		{D5__, quart}, //count = 8
		{C5__, quart}, //count = 9
		////////////////
		{A4__, half}, //count = 10
		{E5__, quart}, //count = 11
		{D5__, quart}, //count = 12
		////////////////
		{D5__, eighth}, //count = 13
		{D5__, eighth}, //count = 14
		{D5__, eighth}, //count = 15
		{D5__, eighth}, //count = 16
		{D5__, quart}, //count = 17
		{C5__, quart}, //count = 18
		////////////////
		{A4__, half}, //count = 19
		{D5__, eighth}, //count = 20
		{D5__, eighth}, //count = 21
		{D5__, quart}, //count = 22
		////////////////
		{D5__, quart}, //count = 23
		{D5__, eighth}, //count = 24
		{D5__, eighth}, //count = 25
		{E5__, quart}, //count = 26
		{C5__, quart}, //count = 27
		////////////////   //7
		{A4__, half}, //count = 28
		{E5__, quart}, //count = 29
		{D5__, quart}, //count = 30
		////////////////
		{D5__, quart}, //count = 31
		{D5__, eighth}, //count = 32
		{D5__, eighth}, //count = 33
		{D5__, quart}, //count = 34
		{C5__, quart}, //count = 35
		////////////////
		{A4__, half}, //count = 36
		{D5__, eighth}, //count = 37
		{D5__, eighth}, //count = 38
		{D5__, quart}, //count = 39
		////////////////
		{D5__, quart}, //count = 40
		{D5__, eighth}, //count = 41
		{D5__, eighth}, //count = 42
		{E5__, quart}, //count = 43
		{C5__, quart}, //count = 44
		////////////////
		{A4__, half}, //count = 45
		{D5__, eighth}, //count = 46
		{D5__, eighth}, //count = 47
		{D5__, quart}, //count = 48
		////////////////
		{D5__, quart}, //count = 49
		{D5__, eighth}, //count = 50
		{D5__, eighth}, //count = 51
		{E5__, quart}, //count = 52
		{C5__, quart}, //count = 53
		////////////////
		{A4__, half}, //count = 54
		{D5__, quart}, //count = 55
		{D5__, quart}, //count = 56
		//////////////// 14
		{D5__, eighth}, //count = 57
		{D5__, eighth}, //count = 58
		{D5__, quart}, //count = 59
		{E5__, quart}, //count = 60
		{C5__, quart}, //count = 61
		////////////////
		{D5__, half}, //count = 62
		{E5__, quart}, //count = 63
		{D5__, quart}, //count = 64
		////////////////
		{D5__, eighth}, //count = 65
		{D5__, eighth}, //count = 66
		{D5__, quart}, //count = 67
		{E5__, quart}, //count = 68
		{C5__, quart}, //count = 69
		{A4__, halfDot}, //count = 70
		//////////////// CODA
	};

	unsigned float beforeRepeat[157][2] = {  //count 71 (count - 71) -> count 227

		{E5__, eighth}, //count = 71, array pos = 1
		{E5__, eighth}, //count = 72, array pos = 2

		{E5__, eighth}, //count = 73, array pos = 3
		{E5__, eighth}, //count = 74, array pos = 4
		{E5__, eighth}, //count = 75, array pos = 5
		{E5__, eighth}, //count = 76, array pos = 6
		{E5__, eighth}, //count = 77, array pos = 7
		{E5__, eighth}, //count = 78, array pos = 8
		{G5__, quart}, //count = 79, array pos = 9

		{E5__, half}, //count = 80, array pos = 10
		{E5__, eighth}, //count = 81, array pos = 11
		{E5__, eighth}, //count = 82, array pos = 12
		{E5__, eighth}, //count = 83, array pos = 13
		{E5__, eighth}, //count = 84, array pos = 14

		//////////////// 20
		{E5__, eighth}, //count = 85, array pos = 15
		{E5__, eighth}, //count = 86, array pos = 16
		{E5__, eighth}, //count = 87, array pos = 17
		{E5__, eighth}, //count = 88, array pos = 18
		{E5__, eighth}, //count = 89, array pos = 19
		{E5__, eighth}, //count = 90, array pos = 20
		{A5__, quart}, //count = 91, array pos = 21

		{E5__, halfDot}, //count = 92, array pos = 22
		{E5__, eighth}, //count = 93, array pos = 23
		{E5__, eighth}, //count = 94, array pos = 24

		{E5__, eighth}, //count = 95, array pos = 25
		{E5__, eighth}, //count = 96, array pos = 26
		{E5__, eighth}, //count = 97, array pos = 27
		{E5__, eighth}, //count = 98, array pos = 28
		{E5__, eighth}, //count = 99, array pos = 29
		{E5__, eighth}, //count = 100, array pos = 30
		{G5__, quart}, //count = 101, array pos = 31

		{E5__, quart}, //count = 102, array pos = 32
		{E5__, eighth}, //count = 103, array pos = 33
		{D5__, eighth}, //count = 104, array pos = 34
		{D5__, eighth}, //count = 105, array pos = 35
		{C5__, eighth}, //count = 106, array pos = 36
		{D5__, eighth}, //count = 107, array pos = 37
		{C5__, eighth}, //count = 108, array pos = 38

		{D5__, quart}, //count = 109, array pos = 39
		{D5__, eighth}, //count = 110, array pos = 40
		{D5__, eighth}, //count = 111, array pos = 41
		{D5__, eighth}, //count = 112, array pos = 42
		{D5__, eighth}, //count = 113, array pos = 43
		{C5__, quart}, //count = 114, array pos = 44

		{0, half}, //count = 115, array pos = 45
		{0, sixteenth}, //count = 116, array pos = 46
		{E5__, sixteenth}, //count = 117, array pos = 47
		{E5__, eighth}, //count = 118, array pos = 48
		{E5__, eighth}, //count = 119, array pos = 49
		//////////////// 26
		{E5__, eighth}, //count = 120, array pos = 50
		{E5__, eighth}, //count = 121, array pos = 51
		{E5__, eighth}, //count = 122, array pos = 52
		{E5__, eighth}, //count = 123, array pos = 53
		{E5__, eighth}, //count = 124, array pos = 54
		{E5__, eighth}, //count = 125, array pos = 55
		{G5__, quart}, //count = 126, array pos = 56

		{E5__, half}, //count = 127, array pos = 57
		{E5__, eighth}, //count = 128, array pos = 58
		{E5__, eighth}, //count = 129, array pos = 59
		{E5__, eighth}, //count = 130, array pos = 60
		{E5__, eighth}, //count = 131, array pos = 61

		{E5__, eighth}, //count = 132, array pos = 62
		{E5__, eighth}, //count = 133, array pos = 63
		{E5__, eighth}, //count = 134, array pos = 64
		{E5__, eighth}, //count = 135, array pos = 65
		{E5__, eighth}, //count = 136, array pos = 66
		{E5__, eighth}, //count = 137, array pos = 67
		{A5__, quart}, //count = 138, array pos = 68

		{E5__, half}, //count = 139, array pos = 69
		{E5__, eighth}, //count = 140, array pos = 70
		{E5__, eighth}, //count = 141, array pos = 71
		{E5__, eighth}, //count = 142, array pos = 72
		{E5__, eighth}, //count = 143, array pos = 73

		{E5__, quart}, //count = 144, array pos = 74
		{E5__, eighth}, //count = 145, array pos = 75
		{E5__, eighth}, //count = 146, array pos = 76
		{E5__, eighth}, //count = 147, array pos = 77
		{E5__, eighth}, //count = 148, array pos = 78
		{G5__, quart}, //count = 149, array pos = 79

		{E5__, quart}, //count = 150, array pos = 80
		{D5__, quart}, //count = 151, array pos = 81
		{D5__, eighth}, //count = 152, array pos = 82
		{E5__, eighth}, //count = 153, array pos = 83
		{D5__, eighth}, //count = 154, array pos = 84
		{C5__, eighth}, //count = 155, array pos = 85
		///////////////// 32
		{D5__, quart}, //count = 156, array pos = 86
		{D5__, eighth}, //count = 157, array pos = 87
		{D5__, eighth}, //count = 158, array pos = 88
		{D5__, eighth}, //count = 159, array pos = 89
		{D5__, eighth}, //count = 160, array pos = 90
		{C5__, quart}, //count = 161, array pos = 91

		{0, quart}, //count = 162, array pos = 92
		{A4__, half}, //count = 163, array pos = 93
		{A4__, quart}, //count = 164, array pos = 94

		{A4__, quartDot}, //count = 165, array pos = 95
		{A4__, eighth}, //count = 166, array pos = 96
		{A4__, quart}, //count = 167, array pos = 97
		{A4__, quart}, //count = 168, array pos = 98

		{0, quart}, //count = 169, array pos = 99
		{G4__, half}, //count = 170, array pos = 100
		{G4__, quart}, //count = 171, array pos = 101

		{G4__, quartDot}, //count = 172, array pos = 102
		{G4__, eighth}, //count = 173, array pos = 103
		{E5__, eighth}, //count = 174, array pos = 104
		{G5__, eighth}, //count = 175, array pos = 105
		{E5__, eighth}, //count = 176, array pos = 106
		{A5__, eighth}, //count = 177, array pos = 107

		{0, quart}, //count = 178, array pos = 108
		{F4__, half}, //count = 179, array pos = 109
		{F4__, quart}, //count = 180, array pos = 110

		{F4__, quartDot}, //count = 181, array pos = 111
		{F4__, eighth}, //count = 182, array pos = 112
		{F4__, quart}, //count = 183, array pos = 113
		{F4__, quart}, //count = 184, array pos = 114
		//////////////////////// 39
		{0, quart}, //count = 185, array pos = 115
		{G4__, half}, //count = 186, array pos = 116
		{G4__, quart}, //count = 187, array pos = 117

		{G4__, quart}, //count = 188, array pos = 118
		{D5__, eighth}, //count = 189, array pos = 119
		{D5__, eighth}, //count = 190, array pos = 120
		{D5__, eighth}, //count = 191, array pos = 121
		{D5__, eighth}, //count = 192, array pos = 122
		{D5__, eighth}, //count = 193, array pos = 123
		{D5__, eighth}, //count = 194, array pos = 124

		{D5__, quart}, //count = 195, array pos = 125
		{C5__, half}, //count = 196, array pos = 126
		{A4__, quart}, //count = 197, array pos = 127

		{A4__, quartDot}, //count = 198, array pos = 128
		{A4__, eighth}, //count = 199, array pos = 129
		{A4__, quart}, //count = 200, array pos = 130
		{A4__, quart}, //count = 201, array pos = 131

		{0, quart}, //count = 202, array pos = 132
		{G4__, half}, //count = 203, array pos = 133
		{G4__, quart}, //count = 204, array pos = 134

		{G4__, quartDot}, //count = 205, array pos = 135
		{G4__, eighth}, //count = 206, array pos = 136
		{E5__, eighth}, //count = 207, array pos = 137
		{G5__, eighth}, //count = 208, array pos = 138
		{E5__, eighth}, //count = 209, array pos = 139
		{A5__, eighth}, //count = 210, array pos = 140

		{0, quart}, //count = 211, array pos = 141
		{F4__, half}, //count = 212, array pos = 142
		{F4__, quart}, //count = 213, array pos = 143
		/////////////////////46
		{F4__, quartDot}, //count = 214, array pos = 144
		{F4__, eighth}, //count = 215, array pos = 145
		{F4__, quart}, //count = 216, array pos = 146
		{F4__, quart}, //count = 217, array pos = 147

		{0, quart}, //count = 218, array pos = 148
		{G4__, half}, //count = 219, array pos = 149
		{G4__, quart}, //count = 220, array pos = 150

		{G4__, quart}, //count = 221, array pos = 151
		{D5__, eighth}, //count = 222, array pos = 152
		{D5__, eighth}, //count = 223, array pos = 153
		{D5__, eighth}, //count = 224, array pos = 154
		{D5__, eighth}, //count = 225, array pos = 155
		{D5__, eighth}, //count = 226, array pos = 156
		{D5__, eighth}, //count = 227, array pos = 157
		///////////TOOO CODA //
	};

	unsigned float chorus1[89][2] = {  //count 228 (count - 228) -> count 316
		{D5__, quart}, //count = 228, array pos = 0
		{C5__, quart}, //count = 229, array pos = 1
		{D5__, eighth}, //count = 230, array pos = 2
		{D5__, eighth}, //count = 231, array pos = 3
		{D5__, eighth}, //count = 232, array pos = 4
		{D5__, eighth}, //count = 233, array pos = 5


		{D5__, eighth}, //count = 234, array pos = 6
		{D5__, eighth}, //count = 235, array pos = 7
		{D5__, eighth}, //count = 236, array pos = 8
		{D5__, eighth}, //count = 237, array pos = 9
		{D5__, quart}, //count = 238, array pos = 10
		{C5__, quart}, //count = 239, array pos = 11

		{A4__, half}, //count = 240, array pos = 12
		{D5__, eighth}, //count = 241, array pos = 13
		{D5__, eighth}, //count = 242, array pos = 14
		{D5__, eighth}, //count = 243, array pos = 15
		{D5__, eighth}, //count = 244, array pos = 16


		{D5__, eighth}, //count = 245, array pos = 17
		{D5__, eighth}, //count = 246, array pos = 18
		{D5__, eighth}, //count = 247, array pos = 19
		{D5__, eighth}, //count = 248, array pos = 20
		{D5__, quart}, //count = 249, array pos = 21
		{C5__, quart}, //count = 250, array pos = 22
		///////////////53
		{A4__, half}, //count = 251, array pos = 23
		{D5__, eighth}, //count = 252, array pos = 24
		{D5__, eighth}, //count = 253, array pos = 25
		{D5__, eighth}, //count = 254, array pos = 26
		{D5__, eighth}, //count = 255, array pos = 27

		{D5__, quart}, //count = 256, array pos = 28
		{D5__, quart}, //count = 257, array pos = 29
		{E5__, quart}, //count = 258, array pos = 30
		{C5__, quart}, //count = 259, array pos = 31

		{A4__, half}, //count = 260, array pos = 32
		{D5__, eighth}, //count = 261, array pos = 33
		{D5__, eighth}, //count = 262, array pos = 34
		{D5__, eighth}, //count = 263, array pos = 35
		{D5__, eighth}, //count = 264, array pos = 36

		{D5__, quart}, //count = 265, array pos = 37
		{D5__, eighth}, //count = 266, array pos = 38
		{D5__, eighth}, //count = 267, array pos = 39
		{E5__, quart}, //count = 268, array pos = 40
		{C5__, quart}, //count = 269, array pos = 41

		{A4__, half}, //count = 270, array pos = 42
		{D5__, eighth}, //count = 271, array pos = 43
		{D5__, eighth}, //count = 272, array pos = 44
		{D5__, eighth}, //count = 273, array pos = 45
		{D5__, eighth}, //count = 274, array pos = 46

		{D5__, quart}, //count = 275, array pos = 47
		{D5__, eighth}, //count = 276, array pos = 48
		{D5__, eighth}, //count = 277, array pos = 49
		{E5__, quart}, //count = 278, array pos = 50
		{C5__, quart}, //count = 279, array pos = 51

		{D5__, half}, //count = 280, array pos = 52
		{0, eighth}, //count = 281, array pos = 53
		{D5__, eighth}, //count = 282, array pos = 54
		{D5__, eighth}, //count = 283, array pos = 55
		{D5__, eighth}, //count = 284, array pos = 56
		///////////////////60
		{D5__, quart}, //count = 285, array pos = 57
		{D5__, eighth}, //count = 286, array pos = 58
		{D5__, eighth}, //count = 287, array pos = 59
		{E5__, quart}, //count = 288, array pos = 60
		{C5__, quart}, //count = 289, array pos = 61

		{C5__, quart}, //count = 290, array pos = 62
		{A4__, quart}, //count = 291, array pos = 63
		{0, eighth}, //count = 292, array pos = 64
		{D5__, eighth}, //count = 293, array pos = 65
		{D5__, eighth}, //count = 294, array pos = 66
		{D5__, eighth}, //count = 295, array pos = 67

		{D5__, eighth}, //count = 296, array pos = 68
		{D5__, eighth}, //count = 297, array pos = 69
		{D5__, eighth}, //count = 298, array pos = 70
		{D5__, eighth}, //count = 299, array pos = 71
		{D5__, eighth}, //count = 300, array pos = 72
		{D5__, eighth}, //count = 301, array pos = 73
		{D5__, eighth}, //count = 302, array pos = 74
		{D5__, eighth}, //count = 303, array pos = 75

		{0, eighth}, //count = 304, array pos = 76
		{D5__, eighth}, //count = 305, array pos = 77
		{D5__, eighth}, //count = 306, array pos = 78
		{D5__, eighth}, //count = 307, array pos = 79
		{D5__, quart}, //count = 308, array pos = 80
		{D5__, quart}, //count = 309, array pos = 81

		{D5__, quart}, //count = 310, array pos = 82
		{D5__, eighth}, //count = 311, array pos = 83
		{D5__, eighth}, //count = 312, array pos = 84
		{E5__, eighth}, //count = 313, array pos = 85
		{C5__, eighth}, //count = 314, array pos = 86
		{C5__, eighth}, //count = 315, array pos = 87
		{A4__, eighth}, //count = 316, array pos = 88
	};

unsigned float chorus2[88][2] = {  //count 317 (count - 317) - > count 404
		{D5__, quart}, //count = 317, array pos = 0
		{C5__, quart}, //count = 318, array pos = 1
		{0, half}, //count = 319, array pos = 2
		////////////////////66
		{C5__, eighth}, //count = 320, array pos = 3
		{C5__, eighth}, //count = 321, array pos = 4
		{C5__, eighth}, //count = 322, array pos = 5
		{C5__, eighth}, //count = 323, array pos = 6
		{C5__, quart}, //count = 324, array pos = 7
		{C5__, quart}, //count = 325, array pos = 8

		{B4__, eighth}, //count = 326, array pos = 9
		{B4__, eighth}, //count = 327, array pos = 10
		{B4__, eighth}, //count = 328, array pos = 11
		{B4__, eighth}, //count = 329, array pos = 12
		{B4__, quart}, //count = 330, array pos = 13
		{B4__, eighth}, //count = 331, array pos = 14
		{B4__, eighth}, //count = 332, array pos = 15

		{B4__, quart}, //count = 333, array pos = 16
		{B4__, eighth}, //count = 334, array pos = 17
		{B4__, eighth}, //count = 335, array pos = 18
		{B4__, quart}, //count = 336, array pos = 19
		{A4__, quart}, //count = 337, array pos = 20

		{C5__, eighth}, //count = 338, array pos = 21
		{C5__, eighth}, //count = 339, array pos = 22
		{C5__, eighth}, //count = 340, array pos = 23
		{C5__, eighth}, //count = 341, array pos = 24
		{C5__, quart}, //count = 342, array pos = 25
		{C5__, eighth}, //count = 343, array pos = 26
		{C5__, eighth}, //count = 344, array pos = 27

		{C5__, quart}, //count = 345, array pos = 28
		{C5__, quart}, //count = 346, array pos = 29
		{C5__, quart}, //count = 347, array pos = 30
		{D5__, quart}, //count = 348, array pos = 31

		{B4__, eighth}, //count = 349, array pos = 32
		{B4__, eighth}, //count = 350, array pos = 33
		{B4__, eighth}, //count = 351, array pos = 34
		{B4__, eighth}, //count = 352, array pos = 35
		{B4__, quart}, //count = 353, array pos = 36
		{B4__, eighth}, //count = 354, array pos = 37
		{B4__, eighth}, //count = 355, array pos = 38
		/////////////////72
		{B4__, quart}, //count = 356, array pos = 39
		{B4__, eighth}, //count = 357, array pos = 40
		{B4__, eighth}, //count = 358, array pos = 41
		{B4__, quart}, //count = 359, array pos = 42
		{A4__, quart}, //count = 360, array pos = 43

		{C5__, quart}, //count = 361, array pos = 44
		{C5__, quart}, //count = 362, array pos = 45
		{C5__, quart}, //count = 363, array pos = 46
		{C5__, eighth}, //count = 364, array pos = 47
		{C5__, eighth}, //count = 365, array pos = 48

		{C5__, quart}, //count = 366, array pos = 49
		{C5__, eighth}, //count = 367, array pos = 50
		{D5__, eighth}, //count = 368, array pos = 51
		{D5__, half}, //count = 369, array pos = 52

		{B4__, quart}, //count = 370, array pos = 53
		{B4__, quart}, //count = 371, array pos = 54
		{B4__, quart}, //count = 372, array pos = 55
		{B4__, eighth}, //count = 373, array pos = 56
		{B4__, eighth}, //count = 374, array pos = 57

		{B4__, quart}, //count = 375, array pos = 58
		{B4__, eighth}, //count = 376, array pos = 59
		{B4__, eighth}, //count = 377, array pos = 60
		{B4__, quart}, //count = 378, array pos = 61
		{A4__, eighth}, //count = 379, array pos = 62
		{A4__, eighth},//count = 380, array pos = 63

		{C5__, eighth}, //count = 381, array pos = 64
		{C5__, eighth}, //count = 382, array pos = 65
		{C5__, eighth}, //count = 383, array pos = 66
		{C5__, eighth}, //count = 384, array pos = 67
		{C5__, quart}, //count = 385, array pos = 68
		{C5__, eighth}, //count = 386, array pos = 69
		{C5__, eighth}, //count = 387, array pos = 70
		///////////////////78
		{C5__, quart}, //count = 388, array pos = 71
		{C5__, eighth}, //count = 389, array pos = 72
		{D5__, eighth}, //count = 390, array pos = 73
		{D5__, quart}, //count = 391, array pos = 74
		{B4__, eighth}, //count = 392, array pos = 75
		{B4__, eighth}, //count = 393, array pos = 76

		{B4__, quart}, //count = 394, array pos = 77
		{B4__, eighth}, //count = 395, array pos = 78
		{D5__, eighth}, //count = 396, array pos = 79
		{D5__, quart}, //count = 397, array pos = 80
		{B4__, eighth}, //count = 398, array pos = 81
		{B4__, eighth}, //count = 399, array pos = 82

		{B4__, quart}, //count = 400, array pos = 83
		{B4__, eighth}, //count = 401, array pos = 84
		{B4__, eighth}, //count = 402, array pos = 85
		{B4__, quart}, //count = 403, array pos = 86
		{A4__, quart}, //count = 404, array pos = 87
	};


#endif
