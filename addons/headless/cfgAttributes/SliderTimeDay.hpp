class GVAR(SliderTimeDay): Title {
	attributeLoad="		(_this controlsGroupCtrl 100) slidersetposition _value;		[_this controlsGroupCtrl 100,_value] call compile gettext (configfile >> 'Cfg3DEN' >> 'Attributes' >> 'SliderTime' >> 'Controls' >> 'Value' >> 'onSliderPosChanged');	";
	attributeSave="		sliderposition (_this controlsGroupCtrl 100)	";
    onValueChanged = "";
	class Controls {
		class Title: Title {};
		class Value: ctrlXSliderH {
			idc=100;
			x="48 * (pixelW * pixelGrid * 	0.50)";
			w="(	82 - 	8 * 3) * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			sliderRange[] = {0,86399};
			sliderPosition = 43200;
			pageSize = 1;
			onSliderPosChanged = "				comment 'DO NOT COPY THIS CODE TO YOUR ATTRIBUTE CONFIG UNLESS YOU ARE CHANGING SOMETHING IN THE CODE!';				_ctrlSlider = _this select 0;				_value = (_this select 1) * (sliderspeed _ctrlSlider select 1);				_valueHour = floor (_value / 3600);				_valueMinute = floor ((_value / 60) % 60);				_valueSecond = floor (_value % 60);				_textHour = if (_valueHour < 10) then {'0' + str _valueHour} else {str _valueHour};				_textMinute = if (_valueMinute < 10) then {'0' + str _valueMinute} else {str _valueMinute};				_textSecond = if (_valueSecond < 10) then {'0' + str _valueSecond} else {str _valueSecond};				_ctrlGroup = ctrlParentControlsGroup _ctrlSlider;				_ctrlHour = _ctrlGroup controlsgroupctrl 101;				_ctrlMinute = _ctrlGroup controlsgroupctrl 102;				_ctrlSecond = _ctrlGroup controlsgroupctrl 103;				_ctrlHour ctrlsettext _textHour;				_ctrlMinute ctrlsettext _textMinute;				_ctrlSecond ctrlsettext _textSecond;				_ctrlCfg = configfile >> 'Cfg3DEN' >> 'Attributes' >> ctrlclassname _ctrlGroup;				_code = gettext (_ctrlCfg >> 'onValueChanged');				if (_code != '') then {[_ctrlGroup,_value] call compile _code;};			";
		};
		class Frame: ctrlStaticFrame {
			x="(	48 + 	82 - 	8 * 3) * (pixelW * pixelGrid * 	0.50)";
			w="3 * 	8 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
		};
		class Separator: ctrlStatic {
			style=2;
			x="(	48 + 	82 - 	8 * 3) * (pixelW * pixelGrid * 	0.50)";
			w="3 * 	8 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			font="EtelkaMonospacePro";
			sizeEx="3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
			colorBackground[]={0,0,0,0.5};
			text=":   :";
		};
		class Hour: ctrlEdit {
			idc=101;
			text="00";
			tooltip="$STR_3DEN_Attributes_SliderTime_Hour_tooltip";
			style="0x02 + 0x200";
			x="(	48 + 	82 - 	8 * 3) * (pixelW * pixelGrid * 	0.50)";
			w="8 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			colorBackground[]={0,0,0,0};
			font="EtelkaMonospacePro";
			sizeEx="3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
			onKillFocus="				comment 'DO NOT COPY THIS CODE TO YOUR ATTRIBUTE CONFIG UNLESS YOU ARE CHANGING SOMETHING IN THE CODE!';				_ctrlGroup = ctrlParentControlsGroup (_this select 0);				_ctrlSlider = _ctrlGroup controlsgroupctrl 100;				_ctrlHour = _ctrlGroup controlsgroupctrl 101;				_ctrlMinute = _ctrlGroup controlsgroupctrl 102;				_ctrlSecond = _ctrlGroup controlsgroupctrl 103;				_range = sliderrange _ctrlSlider;				_value = (round (parsenumber ctrltext _ctrlHour) + round (parsenumber ctrltext _ctrlMinute) / 60 + round (parsenumber ctrltext _ctrlSecond) / 3600) * 3600;				_ctrlSlider slidersetposition (_value / (sliderspeed _ctrlSlider select 1));				_ctrlCfg = configfile >> 'Cfg3DEN' >> 'Attributes' >> ctrlclassname _ctrlGroup;				[_ctrlSlider,sliderposition _ctrlSlider] call compile gettext (_ctrlCfg >> 'Controls' >> 'Value' >> 'onSliderPosChanged');			";
		};
		class Minute: Hour {
			idc=102;
			tooltip="$STR_3DEN_Attributes_SliderTime_Minute_tooltip";
			x="(	48 + 	82 - 	8 * 2) * (pixelW * pixelGrid * 	0.50)";
			w="8 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
		};
		class Second: Hour {
			idc=103;
			tooltip="$STR_3DEN_Attributes_SliderTime_Second_tooltip";
			x="(	48 + 	82 - 	8) * (pixelW * pixelGrid * 	0.50)";
			w="8 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
		};
	};
};
