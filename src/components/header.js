import React from 'react';
import {Link} from 'react-router-dom';

function Header () {
	return (
		<nav className='navbar navbar-expand-lg navbar-dark bg-primary justify-content-between d-flex'>
			<div className='container'>
				<Link to={'/'} className='text-light'>
					<h1>CRUD - React, Redux, REST API & Axios</h1>
				</Link>
				<Link to={'/products/new'} className='btn btn-danger nuevo-post'>
					Add Product &#43;
				</Link>
			</div>
		</nav>
	);
}

export default Header;