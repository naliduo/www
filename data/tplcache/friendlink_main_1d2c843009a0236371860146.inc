<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>�������ӹ���</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
<script language='javascript'>
function Sel(stype)
{
	  for(var i=0;i < document.getElementsByName('aids').length;i++)
	  {
		  if(stype=='all') document.getElementsByName('aids')[i].checked=true;
		  else document.getElementsByName('aids')[i].checked=false;
	  }
}
function checkSubmit()
{
	var str = '';
	for(var i=0;i < document.getElementsByName('aids').length;i++)
	{
		  if(document.getElementsByName('aids')[i].checked){
		  	if(str=='') str += document.getElementsByName('aids')[i].value;
		  	else str += ',' + document.getElementsByName('aids')[i].value;
		  }
	}
	if(str=='')
	{
		alert('��ûѡ���κ����ݣ�');
		return false;
	}
	else
	{
		location="friendlink_edit.php?aids="+str+"&dopost=delall";
	}
}
</script>
</head>
<body>

<div id="main-content">
<script language="javascript">
$("#plus").addClass("current");$("#friendlink_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>�������ӹ���</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D6D6D6">
  <tr>
    <td colspan="8" style="padding-left:10px;">
  <div style="float:left">
		[<a href="friendlink_add.php"><u>��������</u></a>]
 	 	[<a href="friendlink_type.php"><u>��վ���͹���</u></a>]
  	[<a href='<?php echo $GLOBALS['cfg_phpurl']; ?>/flink.php' target='_blank'><u>��������Ԥ��</u></a>]
	</div>

  </td>
</tr>
<tr>
   <td height="30" align="center" colspan="8"> 
   <form action="friendlink_main.php" name="form1" method="get">
	  
          �ؼ��֣�
          <input name="keyword" type="text" id="keyword" size="12" style="width:250px" value="<?php echo $keyword; ?>" />
          
          	<select name="ischeck" id="ischeck">
        			<?php
        			foreach($selCheckArr as $k=>$v)
        			{
        				if($k==$ischeck) echo "<option value='$k' selected>$v</option>\r\n";
        				else echo "<option value='$k'>$v</option>\r\n";
        			}
        			?>
						</select>
          
           <input name="imageField" class="np" type="image" src="images/button_search.gif" width="60" height="22" border="0" />
          
	  </form>
    </td>
</tr>
<form name='form1' method='post' action='friendlink_edit.php' onSubmit='return checkSubmit();'>
<input type='hidden' name='dopost' value='delall'/>
<input type='hidden' name='allid' value=''/>
<tr align="center" bgcolor="#FBFCE2" height="26">
          <td width="6%">ѡ��</td>
          <td width="23%">��վ����</td>
          <td width="12%">��վLogo</td>
          <td width="15%">վ��Email</td>
          <td width="15%">ʱ��</td>
          <td width="8%">״̬</td>
          <td width="8%">˳��</td>
          <td width="15%">����</td>
        </tr>
        <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
        <tr align="center" bgcolor="#FFFFFF" height="26" onMouseMove="javascript:this.bgColor='#FCFDEE';"
        	 onMouseOut="javascript:this.bgColor='#FFFFFF';">
          <td><input type='checkbox' name='aids' value='<?php echo $fields['id']; ?>' class='np'></td>
          <td><a href="<?php echo $fields['url']; ?>" target='_blank'><?php echo htmlspecialchars($fields['webname']); ?></a></td>
          <td><a href="<?php echo $fields['url']; ?>" target='_blank'><?php echo GetPic($fields['logo']); ?></a></td>
          <td><?php echo $fields['email']; ?></td>
          <td><?php echo MyDate('Y-m-d',$fields['dtime']); ?></td>
          <td><?php echo GetSta($fields['ischeck']); ?></td>
          <td><?php echo $fields['sortrank']; ?></td>
          <td>
          	<a href='friendlink_edit.php?id=<?php echo $fields['id']; ?>&dopost=getedit'>[����]</a>
		        <a href='friendlink_edit.php?id=<?php echo $fields['id']; ?>&dopost=delete'>[ɾ��]</a>
		      </td>
        </tr>
		<?php
}
}?>
    </form>
     <tr bgcolor="#ffffff" height="28">
      <td colspan="8">
      	<input class="button" onclick='Sel("all")' name="imageField" type="button" value="ȫѡ" />
       <input class="button" onclick='Sel("none")' name="imageField" type="button" value="ȡ��" />
       <input class="button" onclick='checkSubmit()' name="imageField" type="button" value="����ɾ��" />
      	

      </td>
     </tr>
     <tr align="center" bgcolor="#F9FCEF" height="28">
      <td colspan="8">
      	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

      </td>
     </tr>
   </table>
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