import React, {Fragment} from 'react';
// eso es para las rutas
import {BrowserRouter as Router, Route, Switch} from 'react-router-dom';
import Header from './components/header';
import Products from './components/products';
import NewProduct from './components/newProduct';
import EditProduct from './components/editProduct';
// redux
import {Provider} from 'react-redux';
import store from './store';

function App() {
	return (
		<Router>
			<Provider store={store}>
				<Fragment>
					<Header />
					<div className='container'>
						<Switch>
							<Route exact path='/' component={Products} />
							<Route exact path='/products/new' component={NewProduct} />
							<Route exact path='/products/edit/:id' component={EditProduct} />
						</Switch>
					</div>
				</Fragment>
			</Provider>
		</Router>
	);
}

export default App;
