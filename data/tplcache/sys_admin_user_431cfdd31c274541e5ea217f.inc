<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>����Ա�ʺ�</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>

</head>
<body>

<div id="main-content">
<script language="javascript">
$("#sys").addClass("current");$("#sys_admin_user").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>����Ա�ʺ�</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="2" cellspacing="1" bgcolor="#D6D6D6">
  <tr>
    <td height="27" colspan="5" background="images/tbg.gif" bgcolor="#E7E7E7">
    <b>
          	<a href="sys_admin_user_tj.php"><u>�༭��Чͳ��</u></a>
          	|
          	<a href="sys_admin_user_add.php"><u>���ӹ���Ա</u></a>
          	|
          	<a href="sys_group.php"><u>�û������</u></a>
          	</b>

     </td>
  </tr>
  <tr bgcolor="#FFFFFF">
    <td height="24" colspan="5">����Ϊ�˷�ֹ���������ϵͳ�������ڹ�������ɾ����������Ա�����ȷʵҪɾ���������������ݱ�dede_admin��ɾ����</td>
  </tr>
  <tr bgcolor="#FBFCE2">
    <td width="18%" height="24" align="center">��¼ID</td>
    <td width="13%" align="center">����</td>
    <td width="22%" align="center">����</td>
    <td width="22%" align="center">Ƶ��</td>
    <td width="23%" align="center">������</td>
  </tr>
  <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
  <tr bgcolor="#FFFFFF" align="center">
    <td rowspan="2"><?php echo $fields['userid']; ?></td>
    <td rowspan="2"><?php echo $fields['uname']; ?><br> </td>
    <td><?php echo GetUserType($fields['usertype']); ?></td>
    <td><?php echo GetChannel($fields['typename']); ?></td>
    <td rowspan="2">
	   <a href='sys_admin_user_edit.php?id=<?php echo $fields['id']; ?>&dopost=edit'><u>����</u></a> |
     <a href='sys_admin_user_edit.php?id=<?php echo $fields['id']; ?>&userid=<?php echo $fields['userid']; ?>&dopost=delete'><u>ɾ��</u></a> |
     <a href='content_list.php?mid=<?php echo $fields['id']; ?>'><u>�ĵ�</u></a>��
    </td>
  </tr>
  <tr>
  <td colspan="2" align="center" bgcolor="#FFFFFF">
	��¼ʱ�䣺<?php echo GetDateTimeMk($fields['logintime']); ?>����¼IP��<?php echo $fields['loginip']; ?>
	</td>
  </tr>
  <?php
}
}?>
  <tr bgcolor="#F9FCEF">
    <td height="24" colspan="5" align="center" valign="top">
    	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '7';
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