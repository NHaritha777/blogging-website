import React, { useEffect, useState } from 'react'
import API from '../api'
import PostCard from '../components/PostCard'


export default function Home(){
const [posts, setPosts] = useState([])


useEffect(()=>{
API.get('/posts').then(res => setPosts(res.data)).catch(console.error)
},[])


return (
<div>
<h1 className="text-3xl font-bold mb-4">Latest Posts</h1>
<div className="grid md:grid-cols-2 gap-4">
{posts.map(p=> <PostCard key={p._id} post={{...p, authorName: p.author?.name}} />)}
</div>
</div>
)
}