delete from Interfaces
where FullName = 'Windows::Foundation::IAsyncAction';

delete from Interfaces
where FullName = 'Windows::Foundation::AsyncActionCompletedHandler';

delete from Structures where FullName = 'Windows::Foundation::Point';
delete from Structures where FullName = 'Windows::Foundation::Size';
delete from Structures where FullName = 'Windows::Foundation::TimeSpan';

delete from Structures where FullName = 'Windows::Foundation::Numerics::Vector2';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Vector3';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Vector4';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Matrix3x2';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Matrix4x4';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Plane';
delete from Structures where FullName = 'Windows::Foundation::Numerics::Quaternion';

update Fields set Type = 'Windows::Foundation::Numerics::float2' where Type = 'Windows::Foundation::Numerics::Vector2';
update Fields set Type = 'Windows::Foundation::Numerics::float3' where Type = 'Windows::Foundation::Numerics::Vector3';
update Fields set Type = 'Windows::Foundation::Numerics::float4' where Type = 'Windows::Foundation::Numerics::Vector4';
update Fields set Type = 'Windows::Foundation::Numerics::float3x2' where Type = 'Windows::Foundation::Numerics::Matrix3x2';
update Fields set Type = 'Windows::Foundation::Numerics::float4x4' where Type = 'Windows::Foundation::Numerics::Matrix4x4';
update Fields set Type = 'Windows::Foundation::Numerics::plane' where Type = 'Windows::Foundation::Numerics::Plane';
update Fields set Type = 'Windows::Foundation::Numerics::quaternion' where Type = 'Windows::Foundation::Numerics::Quaternion';

update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Vector2', 'Windows::Foundation::Numerics::float2');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Vector3', 'Windows::Foundation::Numerics::float3');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Vector4', 'Windows::Foundation::Numerics::float4');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Matrix3x2', 'Windows::Foundation::Numerics::float3x2');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Matrix4x4', 'Windows::Foundation::Numerics::float4x4');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Plane', 'Windows::Foundation::Numerics::plane');
update Parameters set Type = replace(Type, 'Windows::Foundation::Numerics::Quaternion', 'Windows::Foundation::Numerics::quaternion');

update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Vector2', 'Windows::Foundation::Numerics::float2');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Vector3', 'Windows::Foundation::Numerics::float3');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Vector4', 'Windows::Foundation::Numerics::float4');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Matrix3x2', 'Windows::Foundation::Numerics::float3x2');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Matrix4x4', 'Windows::Foundation::Numerics::float4x4');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Plane', 'Windows::Foundation::Numerics::plane');
update GenericInterfaces set FullName = replace(FullName, 'Windows::Foundation::Numerics::Quaternion', 'Windows::Foundation::Numerics::quaternion');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Vector2', 'Windows::Foundation::Numerics::float2');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Vector3', 'Windows::Foundation::Numerics::float3');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Vector4', 'Windows::Foundation::Numerics::float4');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Matrix3x2', 'Windows::Foundation::Numerics::float3x2');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Matrix4x4', 'Windows::Foundation::Numerics::float4x4');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Plane', 'Windows::Foundation::Numerics::plane');
update GenericInterfaces set Name = replace(Name, 'Windows::Foundation::Numerics::Quaternion', 'Windows::Foundation::Numerics::quaternion');