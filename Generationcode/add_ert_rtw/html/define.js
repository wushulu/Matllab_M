function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:35,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:71,type:"fcn"};
this.def["rtU"] = {file: "add_c.html",line:21,type:"var"};
this.def["rtY"] = {file: "add_c.html",line:24,type:"var"};
this.def["add_step"] = {file: "add_c.html",line:27,type:"fcn"};
this.def["add_initialize"] = {file: "add_c.html",line:50,type:"fcn"};
this.def["ExtU"] = {file: "add_h.html",line:33,type:"type"};
this.def["ExtY"] = {file: "add_h.html",line:38,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:89,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["add_c.html"] = "../add.c";
	this.html2Root["add_c.html"] = "add_c.html";
	this.html2SrcPath["add_h.html"] = "../add.h";
	this.html2Root["add_h.html"] = "add_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","add_c.html","add_h.html","rtwtypes_h.html"];
