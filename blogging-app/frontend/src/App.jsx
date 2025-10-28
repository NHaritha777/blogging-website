import React from 'react'
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import Home from './pages/Home'
import Post from './pages/Post'
import Dashboard from './pages/Dashboard'
import Header from './components/Header'


export default function App(){
return (
<BrowserRouter>
<div className="min-h-screen flex flex-col">
<Header />
<main className="container mx-auto p-4 flex-1">
<Routes>
<Route path="/" element={<Home/>} />
<Route path="/post/:id" element={<Post/>} />
<Route path="/dashboard" element={<Dashboard/>} />
</Routes>
</main>
</div>
</BrowserRouter>
)
}