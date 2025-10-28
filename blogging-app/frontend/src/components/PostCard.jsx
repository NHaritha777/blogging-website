import React from 'react'
import { Link } from 'react-router-dom'


export default function PostCard({ post }){
return (
<div className="p-4 bg-white rounded shadow">
<h3 className="text-lg font-semibold">{post.title}</h3>
<p className="text-sm text-gray-600 my-2">{post.summary || post.content?.slice(0,200) + '...'}</p>
<div className="flex justify-between items-center">
<div className="text-xs text-gray-500">By {post.authorName || 'Unknown'}</div>
<Link to={`/post/${post._id}`} className="text-indigo-600">Read →</Link>
</div>
</div>
)
}