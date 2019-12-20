package test5;   
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
 
public class Product_clo {     //��ȡ��Ʒ���е�ȫ����Ϣ�͹��ﳵ������Ʒid
	ArrayList<Integer> list = new ArrayList<Integer>();
	// ���������Ʒ��ȫ����Ϣ
	public ArrayList<product> getAllProduct() {
		Connection conn = null;
		PreparedStatement stmt = null;
		ResultSet rs = null;
		ArrayList<product> list = new ArrayList<product>();// ����Ʒ��Ϣ���б���
		try {
			conn = DataBaseConnection.getConnection();
			String sql = "select * from product;";
			stmt = conn.prepareStatement(sql);
			rs = stmt.executeQuery();
			while (rs.next()) {
				product product = new product();
				product.setId(rs.getInt("product_id"));
				product.setName(rs.getString("product_name"));
				product.setMsg(rs.getString("product_msg"));
				product.setPrice(rs.getInt("product_price"));
				product.setType(rs.getString("product_type"));
				product.setQuantity(rs.getInt("product_quantity"));
				product.setPicture(rs.getString("product_picture"));
				list.add(product);// ��һ����Ʒ��������Ϣ�����б�
			}
			return list;
		} catch (Exception ex) {
			ex.printStackTrace();
			return null;
		} finally {
			// �ͷ����ݼ�����
			if (rs != null) {
				try {
					rs.close();
					rs = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
			// �ͷ�������
			if (stmt != null) {
				try {
					stmt.close();
					stmt = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
		}
	}
	// ��ȡ���ﳵ��Ʒ��id
	public ArrayList<Integer> getCartId() {
		Connection conn = null;
		PreparedStatement stmt = null;
		ResultSet rs = null;
 
		try {
			conn = DataBaseConnection.getConnection();
			String sql = "select product_id from shopcart;";// SQL���
			stmt = conn.prepareStatement(sql);
			rs = stmt.executeQuery();
			while (rs.next()) {
				list.add(rs.getInt(1));// ��һ����Ʒ��������Ϣ�����б�
			}
			return list;
		} catch (Exception ex) {
			ex.printStackTrace();
			return null;
		} finally {
			// �ͷ����ݼ�����
			if (rs != null) {
				try {
					rs.close();
					rs = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
			// �ͷ�������
			if (stmt != null) {
				try {
					stmt.close();
					stmt = null;
				} catch (Exception ex) {
					// TODO: handle exception
					ex.printStackTrace();
				}
			}
		}
 
	}
	private PreparedStatement setInt(int i, int j) {
		// TODO Auto-generated method stub
		return null;
	}
 
	private PreparedStatement setString(int i, String name) {
		// TODO Auto-generated method stub
		return null;
	}
}
