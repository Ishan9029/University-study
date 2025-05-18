import React from 'react';
import { BrowserRouter, Routes, Route, Link } from 'react-router-dom';
import Home from './Home';
import About from './About';

export default function AppRouter() {
  return (
    <div>
      <BrowserRouter>
        <h1>React Routing Examples</h1>
        <Link to="/">Home</Link>
        <Link to="/About">About</Link>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/About" element={<About />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}
