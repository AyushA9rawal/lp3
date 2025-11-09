// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        string name;
        uint age;
        uint rollNo;
    }

    Student[] public students;
    address public owner;

    event StudentAdded(string name, uint age, uint rollNo);

    event ReceivedEther(address sender, uint amount);
    event FallbackCalled(address sender, uint amount, bytes data);

    constructor() {
        owner = msg.sender;
    }

    function addStudent(string memory _name, uint _age, uint _rollNo) public {
        students.push(Student(_name, _age, _rollNo));
        emit StudentAdded(_name, _age, _rollNo);
    }

    function getTotalStudents() public view returns (uint) {
        return students.length;
    }

    function getStudent(uint index) public view returns (string memory, uint, uint) {
        require(index < students.length, "Invalid index");
        Student memory s = students[index];
        return (s.name, s.age, s.rollNo);
    }

    receive() external payable {
        emit ReceivedEther(msg.sender, msg.value);
        revert("This contract does not accept Ether");
    }

    fallback() external payable {
        emit FallbackCalled(msg.sender, msg.value, msg.data);
    }
}
