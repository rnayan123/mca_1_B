import React from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import HomePage from './components/HomePage';
import BookDetailsPage from './components/BookDetailsPage';

function App() {
  return (
    <Router>
      <Switch>
        <Route exact path="/" component={HomePage} />
        <Route path="/book/:id" component={BookDetailsPage} />
      </Switch>
    </Router>
  );
}

export default App;
