var overlayer_t="���ڴ����������Ժ�...";
/***************************/
/*   main_menu_language   */
/***************************/
var mmenu_bs="��������";
var mmenu_wl="��������";
var mmenu_if="�ӿ�����";
var mmenu_net="��������";
var mmenu_as="�߼�����";
var mmenu_ac="���ʿ���";
var mmenu_qos="��������";
var mmenu_services="Ӧ�÷���";
var mmenu_admin="������Ϣ";
var mmenu_status="״̬��Ϣ";
var mmenu_help="������Ϣ";
var mmenu_logout="�˳�"; 


/***************************/
/*  wireless_set_menu               */
/***************************/
var wiremenu_wi="������Ϣ";
var wiremenu_ws="��������";
var wiremenu_sec="��ȫ";
var wiremenu_rs="Radius������";
var wiremenu_mf="MAC��ַ����";
var wiremenu_qos="QoS";
var wiremenu_wds="WDS����";
var wiremenu_rog="��åAP���";
var wiremenu_as="�߼�����";
var wiremenu_is="��������";

/***************************/
/*  wireless_info_language  */
/***************************/
var winfo_wifi="�����豸";
var winfo_vap="����AP";
var winfo_ssid="SSID";
var winfo_enable="����";
var winfo_chan="Ƶ��";
var winfo_mode="ģʽ";
var winfo_wmode="WLANģʽ";
var winfo_help="<a href=\"javascript:void(openWin('wirelessinfo_help.htm', 650, 500));\">����>></a>";
var winfo_apply="<input type=\"submit\" value=\"����\" >";
var winfo_del_button0="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath0\" value=\"ɾ��\">";
var winfo_del_button1="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath1\" value=\"ɾ��\">";
var winfo_del_button2="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath2\" value=\"ɾ��\">";
var winfo_del_button3="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath3\" value=\"ɾ��\">";
var winfo_del_button4="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath4\" value=\"ɾ��\">";
var winfo_del_button5="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath5\" value=\"ɾ��\">";
var winfo_del_button6="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath6\" value=\"ɾ��\">";
var winfo_del_button7="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath7\" value=\"ɾ��\">";
var winfo_del_button8="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath8\" value=\"ɾ��\">";
var winfo_del_button9="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath9\" value=\"ɾ��\">";
var winfo_del_button10="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath10\" value=\"ɾ��\">";
var winfo_del_button11="<input type=\"button\" onClick=\"delvap(this)\" name=\"ath11\" value=\"ɾ��\">";
var winfo_vap_create="VAP������";
var winfo_vap_name="VAP����";
var winfo_vap_parent="����wifi��";
var winfo_wlan_mode="WLAN MODE��";
var winfo_vap_create_alert1=" �Ѿ����ڣ����Ƿ�ȷ��Ҫ���´�������ȷ��֮�� ";
var winfo_vap_create_alert2=" �����á�";

/***************************/
/*  wireless_set_language  */
/***************************/
var	wset_wap="����AP";
var	wset_selectap="VAPָ��";
var	wset_currentap="��ǰָ��VAP��";
var	wset_staset="STA�ӿ�����";
var	wset_stastate="STA�ӿ�״̬��";
var	wset_associated_ssid="������SSID��";
var	wset_associated_bssid="������BSSID��";
var	wset_find_button="<input type=\"button\" value=\"����\" name=\"scanning\" onclick=\"javascript:g_OpenWindow('scan_vap.htm','650','500')\">";
var	wset_security="��ȫ��";
var	wset_wep_mode="ģʽ��";
var	wset_encrypt_type="���ܷ�ʽ��";
var	wset_wep_key1="WEP��Կ1��";
var	wset_wep_key2="WEP��Կ2��";
var	wset_wep_key3="WEP��Կ3��";
var	wset_wep_key4="WEP��Կ4��";
var	wset_wpa_with="WPA������";
var	wset_wpa_key="��Կ��";
var	wset_wifi_set="wifi��������";
var	wset_enable="ʹ��״̬";
var	wset_broad="�����㲥SSID";
var	wset_network="��������";
var	wset_name="SSID����";
var	wset_region="������";
var	wset_chan="Ƶ�Σ�";
var	wset_mode="����ģʽ:";
var	wset_basic_set="VAP��������";
var	wset_rate="�������ʣ�";
var	wset_beacon_interval="Beacon���ͼ����";
var	wset_label_range="��Ĭ�ϣ�100����Χ��25 - 1000��";
var	wset_help="<a href=\"javascript:void(openWin('wirelesssetting_help.htm', 650, 500));\">����>></a>";
var	wset_apply="<input type=\"submit\" value=\"Ӧ��\" >";
var	wset_sta_apply="<input type=\"button\" name=\"sta_conf\" value=\"Ӧ��\" onclick=\"submit_sta()\">";
var wset_alert_channel="�����ѡ�����ѡ��������������ʹ֮��Ч!";
var wset_selectchan="����AP���ŵ���";
var wset_assocfail="���ݹ���ʧ�ܵ�Ȩֵѡ��AP��";
var wset_assocrssi="�źŽӽ�ʱ�����������ֵѡ��AP��";
var wset_alert_illchar="���зǷ��ַ�������Ϊ����0-9";
var wset_alert_range="ֵ������Χ";
var wset_alert_c1213="ʹ�ŵ�12��13��Ч��Ҫ����AP";
var alert_ssid_null="������ssid��";
var wset_alert_ssid="��������ȷ��ssid��";
var wset_txpower="���书�ʣ�";
var alert_txpower_error="���书���������";
var alert_txpower_null="�����뷢�书�ʡ�";
var alert_bssid_error="BSSID�������,BSSID��ʽ��ð��(:)�����";
var alert_bssid_null="����BSSID��";
var wset_staset_wds="Mesh�ӿ�����";
var wset_stastate_wds="Mesh�ӿ�״̬��";

/***************************/
/*  wireless_security_language  */
/***************************/
var	sec_wst="���߰�ȫ����";
var	sec_wep="���ߵ�Ч����(WEP)";
var	sec_mod="����ģʽ:";
var	sec_wepencry="��Կ����:";
var	sec_etype="��Կ����:";
var	sec_weppass="��Կ���� :";
var	sec_gen="<input type=\"button\" value=\"����\" name=\"Generate\" onclick=\"genstr()\">";
var	sec_key1="WEP��1:";
var	sec_key2="WEP��2:";
var	sec_key3="WEP��3:";
var	sec_key4="WEP��4:";
var	sec_wpa="WPA";
var	sec_wpawith="WPA����:";
var	sec_wpaencry="���ܷ�ʽ:";
var	sec_psk="PSK����";
var	sec_wpapass="��Կ :";
var	sec_cert_type="֤�����ͣ�";
var	sec_sec_type="��ȫ���ͣ�";
var	sec_cert_serverip="֤�������IP��ַ��";
var	sec_cert_as="AS֤�飺";
var	sec_cert_ap="AP֤�飺";
var sec_cert_ca="CA֤�飺";
var sec_alert_wapi_fail="wapi���ܴ��������ԣ�";
var	sec_alert_p12_fail="p12������������ԣ�";
var sec_alert_cert_file="������֤���ļ���";
var sec_p12="p12ʹ�ܣ�";
var sec_p12_pass="���룺";
var	sec_generate_button="<input type=\"button\" value=\"����\" name=\"Generate\" onclick=\"typeselect()\">";
var	sec_help="<a href=\"javascript:void(openWin('wsecurityzh_help.htm', 650, 500));\">����>></a>";
var	sec_apply="<input type=\"submit\" value=\"Ӧ��\" >";
var sec_alert_key_phrase="��Կ���ﳤ�Ȳ���С��8λ";
var sec_alert_wepk1="����ȷ����WEP��1";
var sec_alert_wepk2="����ȷ����WEP��2";
var sec_alert_wepk3="����ȷ����WEP��3";
var sec_alert_wepk4="����ȷ����WEP��4";
var sec_alert_length="�����볤����ȷ����Կ";

/***************************/
/*  radius_language  */
/***************************/
var	radius_rss="Radius��֤������";
var	radius_arss="Radius�Ʒѷ�����";
var	radius_sip="����֤������IP:";
var	radiusc_authport="��֤�˿�:";
var	radius_sk="������Կ:";
var	radius_sip1="������֤������IP:";
var	radiusc_authport1="��֤�˿�:";
var	radius_sk1="������Կ:";
var	radius_aip="���Ʒѷ�����IP:";
var	radiusc_ap="��֤�˿�:";
var	radius_ask="������Կ:";
var	radius_aip1="���üƷѷ�����IP:";
var	radiusc_ap1="�ƷѶ˿�:";
var	radius_ask1="������Կ:";
var	radius_sip="��֤������IP:";
var	radius_aip="�Ʒѷ�����IP:";
var	radiusc_authport="��֤�˿�:";
var	radiusc_ap="�ƷѶ˿�:";
var	radius_sk="������Կ:";
var	radius_help="<a href=\"javascript:void(openWin('radiusserver_help.htm', 650, 500));\">����>></a>";
var	radius_apply="<input type=\"submit\" value=\"Ӧ��\" >";
var radius_alert_ill="���зǷ��ַ����߳��ȴ���5";
var radius_alert_range="ֵ������Χ";
var radius_alert_ip="��������ȷ��IP��ַ";

/***************************/
/*  macfilter_language  */
/***************************/
var	mac_use="����";
var	mac_filter="MAC����";
var	mac_enable="����";
var	mac_disable="����";
var	mac_mode="����ģʽ";
var	mac_prevent="��ֹ���г�����MAC��ַ���������������� ";
var	mac_permit="���������г�����MAC��ַ����������������";
var	mac_add_button="<input id=\"but\" type=\"button\" name=\"insert_one_row\" value=\"����\" onclick='addrulecount();urltable_insRow(\"click\");'/>";
var	mac_del_button="<input id=\"but\" type=\"button\" name=\"delete_one_row\" value=\"ɾ��\" onclick=\"delrulecount();urltable_delRow();\"/>";
var	mac_help="<a href=\"javascript:void(openWin('macfilter_help.htm', 650, 500));\">����>></a>";
var	mac_apply="<input type=\"submit\" value=\"Ӧ��\" >";
var mac_alert_max="�������20��MAC����";
var mac_alert_atleast="����Ҫ����һ��MAC����";

/***************************/
/*  advance_set_language  */
/***************************/
var adv_shortgi="�̾�����";
var adv_extoffset="�ŵ���չ����";
var adv_extoffset_0="����չ";
var adv_extoffset_1="����";
var adv_extoffset_2="����";
var	wset_nonoverlapping="���ص�1��6��11�ŵ���ѡ��";
var	adv_as="�߼�����";
var	adv_rate="��������";
var	adv_rates="(Ĭ��: Auto)";
var	adv_beacon="Beacon֡����ʱ����";
var	adv_beacons="(Ĭ��: 100ms, ��Χ: 25 - 1000)";
var	adv_dtim="DTIM֡����ʱ����";
var	adv_dtims="(Ĭ��: 1, ��Χ: 1 - 15)";
var	adv_frag="��Ƭ����ֵ";
var	adv_frags="(Ĭ��: 2346, ��Χ: 256 - 2346)";
var	adv_diversity="����ת��ģʽ";
var	adv_diversitys="(Ĭ��: true)";
var	adv_tx="��������";
var	adv_txs="(Ĭ��: Auto)";
var	adv_rx="��������";
var	adv_rxs="(Ĭ��: Auto)";
var	adv_pream="ǰ������";
var	adv_preams="(Ĭ��: Short)";
var	adv_power="���ʵ���";
var	adv_power_big="���书��";
var	adv_powers="(��Χ: -10 - 0)";
var	adv_powers_big="(��Χ: 1 - 27dbm)";
var	adv_rts="RTS����ֵ";
var	adv_rtss="(Ĭ��: 2346, ��Χ: 1 - 2346)";
var	wset_count="��������û���";
var	wset_isa="�û�����";
var	wset_puren="ֻ����11n���빦��";
var	adv_wmm="WMM���� ";
var	adv_wmmsupp="WMMʹ��״̬ ";
var	adv_ack="���ظ�ACK";
var	adv_enable="����";
var	adv_disable="����";
var	adv_disables="(Ĭ��: ����)";
var	adv_vlan="���������(vlan)";
var	adv_vlans="��������� ";
var	adv_vid="���������ID";
var	adv_user_set="�����û�����";
var	adv_cast_iso="����/�㲥����";
var	adv_help="<a href=\"javascript:void(openWin('advanceset_help.htm', 650, 500));\">����>></a>";
var	adv_apply="<input type=\"submit\" value=\"Ӧ��\" >";
var adv_cwwmode="�ŵ�����";
var adv_alert_illchar=" ���зǷ��ַ�������Ϊ����0-9��";
var adv_alert_range="ֵ������Χ��";
var adv_must_reboot="�����ѡ�����ѡ����������AP����������Ч!";
/***************************/
/*  wds_set_language  */
/***************************/
var	wds_name="���߷ֲ�ʽϵͳ(WDS)";
var	wds_prop="WDSʹ��״̬:";
var	wds_enable="����";
var	wds_disable="����";
var	wds_role="��ɫ:";
var	wds_root="Rootģʽ";
var	wds_client="Clientģʽ";
var	wds_ssid="�ŽӶ˿ڵ�SSID:";
var	wds_chan="WDSƵ��:";
var	wds_derived="WDS�����ӿڣ�";
var	wds_setmac="WDS MAC�趨��";
var wds_attention="��ȷ��vap���ŵ���Է�һ��";
var	wds_help="<a href=\"javascript:void(openWin('wds_help.htm', 650, 500));\">����>></a>";
var	wds_apply="<input type=\"submit\" value=\"Ӧ��\"  >";

/***************************/
/*  rogue_set_language  */
/***************************/
var	rogue_create="��åAP���";
var	rogue_vid="��åAP���";
var	rogue_select_if="ָ��ɨ��ӿڣ�";
var	rogue_refresh="<input type=\"button\"  value=\"ˢ��\" name=\"refresh\" onclick=\"myrefresh()\" >";
var	rogue_help="<a href=\"javascript:void(openWin('rogueapdetection_help.htm', 650, 500));\">����>></a>";
var	rogue_apply="<input type=\"submit\"  value=\"Ӧ��\"  >";

/***************************/
/*  intelligent_set_language  */
/***************************/
var iset_uplink_detect="������·���";
var iset_eth0_disable="��eth0ȥ��ʱ��";
var iset_eth1_disable="��eth1ȥ��ʱ��";
var iset_detect_interval="�Զ��������";
var iset_minutes="&nbsp;����&nbsp;��0-60���ӣ�";
var iset_uplink_ip="������·IP��ַ��";
var iset_load_balance="���ؾ���";
var iset_lb_enable="ʹ��״̬��";
var iset_lb_threshold="��ֵ��";
var iset_channel_auto="�ŵ��Զ�����";
var iset_wifi0_chanauto="�Զ�����wifi0���ŵ���";
var iset_wifi1_chanauto="�Զ�����wifi1���ŵ���";
var iset_adjust_interval="�Զ����������";
var iset_power_auto="�����Զ�����";
var iset_wifi0_powerauto="�Զ�����wifi0�Ĺ��ʣ�";
var iset_wifi1_powerauto="�Զ�����wifi1�Ĺ��ʣ�";
var	iset_help="<a href=\"javascript:void(openWin('intelligence_help.htm', 650, 500));\">����>></a>";