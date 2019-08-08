class EGVAR(Import,LoadoutFromProfileAttribute): Combo {
    attributeLoad = QUOTE(_this call FUNC(ImportLoadoutFromProfileAttributeAttrLoad));
    attributeSave ="";
	class Controls: Controls {
		class Title: Title {};
		class Value: Value {
			idc = 100;
            x="48 * (pixelW * pixelGrid * 	0.50)";
			w="(	60 - 	5) * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
		};
		class Preview: ctrlButtonPictureKeepAspect {
			idc = 101;
            x="(	48 + 	60 - 	5) * (pixelW * pixelGrid * 	0.50)";
			w="0.99 * 	5 * (pixelW * pixelGrid * 	0.50)";
			h="5 * (pixelH * pixelGrid * 	0.50)";
			text="\a3\3DEN\Data\Attributes\ComboPreview\play_ca.paa";
			onMouseButtonClick= QUOTE(\
				_this params ['_ctrlButton'];\
				_ctrlGroup = ctrlParentControlsGroup _ctrlButton;\
				_ctrlCombo = _ctrlGroup controlsgroupctrl 100;\
				[ARR_2((_ctrlCombo lbData lbcursel _ctrlCombo),0)] call FUNC(ImportLoadoutSettings););
		};
	};
};
