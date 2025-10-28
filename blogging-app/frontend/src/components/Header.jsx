import React, { useState, useEffect } from 'react'
import { Link, useNavigate } from 'react-router-dom'
import AuthForm from './AuthForm'


export default function Header(){
const [user, setUser] = useState(null)
const [showAuth, setShowAuth] = useState(false)
const navigate = useNavigate()


useEffect(()=>{
const u = localStorage.getItem('user')
if(u) setUser(JSON.parse(u))
},[])


function logout(){
localStorage.removeItem('token')
localStorage.removeItem('user')
setUser(null)
navigate('/')
}


return (
<header className="bg-white shadow">
<div className="container mx-auto p-4 flex items-center justify-between">
<div>
<Link to="/" className="text-2xl font-bold text-indigo-600">MyBlog</Link>
</div>
<nav className="flex items-center gap-4">
<Link to="/" className="hover:underline">Home</Link>
{user ? (
<>
<Link to="/dashboard" className="hover:underline">Dashboard</Link>
<button onClick={logout} className="px-3 py-1 bg-red-500 text-white rounded">Logout</button>
</>
) : (
<>
<button onClick={()=>setShowAuth(true)} className="px-3 py-1 bg-indigo-600 text-white rounded">Sign In / Up</button>
</>
)}
</nav>
</div>
{showAuth && <AuthForm onClose={()=>setShowAuth(false)} onAuth={(user)=>{ setUser(user); setShowAuth(false) }} />}
</header>
)
}