<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>����ϵͳ��־</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
<script language="javascript">

//���ѡ���ļ����ļ���
function getCheckboxItem(){
	 var allSel="";
	 if(document.form1.logs.value) return document.form1.logs.value;
	 for(i=0;i<document.form1.logs.length;i++)
	 {
		 if(document.form1.logs[i].checked){
			 if(allSel=="")
				 allSel=document.form1.logs[i].value;
			 else
				 allSel=allSel+"`"+document.form1.logs[i].value;
		 }
	 }
	 return allSel;	
}

function ReSel(){
	for(i=0;i<document.form1.logs.length;i++){
		if(document.form1.logs[i].checked) document.form1.logs[i].checked = false;
		else document.form1.logs[i].checked = true;
	}
}

function DelSel(){
	 var nid = getCheckboxItem();
	 if(nid==""){
		  alert("��ѡ����Ŀ!\r\n");
		  return ;
	 }
	 location.href = "log_edit.php?dopost=del&ids="+nid;
}

function ClearLog(){
	 location.href = "log_edit.php?dopost=clear";
}

</script>
</head>
<body>

<div id="main-content">
<script language="javascript">
$("#sys").addClass("current");$("#log_list").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>����ϵͳ��־</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" cellpadding="2" cellspacing="1" bgcolor="#D6D6D6" align="center">

  <tr align="center" bgcolor="#ffffff"> 
    <td colspan="7">
	  <table width="90%" border="0" cellspacing="0" cellpadding="0">
     <form name='formsearch'>
		  <tr>
       <td>
		  ����Ա��
		  <select name="adminid" id="adminid" style="width:90px">
		  <option value="0" selected>--ȫ��--</option>
		  <?php echo $adminlist?>
		  </select>
		  IP��ַ��
      <input name="cip" type="text" id="cip" size="15" style="width:100px" />
      ʱ�䣺 
      <select name="dtime" id="dtime">
              <option value="0" selected>--ȫ��--</option>
              <option value="7">һ����</option>
              <option value="15">15����</option>
              <option value="30">30������</option>
              <option value="60">60������</option>
        </select> 
			   &nbsp;
               <input class="button" name="Submit" type="submit" value="����" />
       
        </td>
      </tr>
		</form>
    </table>
   </td>
  </tr>
  <tr align="center" bgcolor="#FBFCE2"> 
    <td width="8%">ѡ��</td>
    <td width="11%">����Ա</td>
    <td width="15%">�����ļ�</td>
    <td width="8%">��ʽ</td>
    <td width="14%">����IP</td>
    <td width="16%">ʱ��</td>
    <td width="28%">Query����</td>
  </tr>
  <form name="form1">
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <tr align="center" bgcolor="#FFFFFF" height="26" align="center" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';"> 
      <td>
      	<input name='logs' type='checkbox' class='np' id="logs" value='<?php echo $fields['lid']; ?>' />
      </td>
      <td> 
        <?php echo $fields['userid']; ?>
      </td>
      <td>
      	<input class="np" type="text" value="<?php echo $fields['filename']; ?>" name="t0" style="width:100px" />
      </td>
      <td> 
        <?php echo $fields['method']; ?>
      </td>
      <td> 
        <?php echo $fields['cip']; ?>
      </td>
      <td> 
        <?php echo MyDate('y/m/d H:i:s',$fields['dtime']); ?>
      </td>
      <td>
      	<input class="np" type="text" value="<?php echo $fields['query']; ?>" name="t1" style="width:280px" />
      </td>
    </tr>
<?php
}
}?>
  </form>
  <tr> 
    <td height="30" colspan="7" bgcolor="#FCFDF7">
    	&nbsp; <input class="button" name="b5" type="button" value="��ѡ" onClick="ReSel();" />

      &nbsp;  <input class="button" name="b6" type="button" value="ɾ����ѡ" onClick="DelSel();" />

      &nbsp; <input class="button" name="b7" type="button" value="���������־" onClick="ClearLog();" />

    </td>
  </tr>
  <tr bgcolor="#F9FCEF"> 
    <td height="24" colspan="7" align="center"> 
      <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '5';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

    </td>
  </tr>
</table>
							<div class="clear"></div><!-- End .clear -->
							
						
						
					</div> <!-- End #tab1 -->

					
				</div> <!-- End .content-box-content -->
				
			</div> <!-- End .content-box -->
			
			<div class="clear"></div>
			
           <?php include(DEDEADMIN.'/templets/footer.htm'); ?>
			
		</div> <!-- End #main-content -->	
	</div>
</body>
</html>