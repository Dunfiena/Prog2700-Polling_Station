
USE [DBAS4002-2023_ELECTION]
GO

--Generate the 2 candidates that have the most number of votes--
-----------------------------------------------------------------
SELECT TOP 2 v.CandidateId, c.FirstName, c.LastName, COUNT(v.CandidateID) as NumberOfVotes
FROM Votes v
join (Select FirstName, LastName, CandidateID From Candidate) c
on c.CandidateID=v.CandidateID
GROUP BY c.FirstName,c.LastName,v.CandidateID
ORDER BY NumberOfVotes desc;

--Generate the Candiate with the least votes
-----------------------------------------------------------------
SELECT TOP 1 v.CandidateId, c.FirstName, c.LastName, COUNT(v.CandidateID) as NumberOfVotes
FROM Votes v
join (Select FirstName, LastName, CandidateID From Candidate) c
on c.CandidateID=v.CandidateID
GROUP BY c.FirstName,c.LastName,v.CandidateID
ORDER BY NumberOfVotes asc;

--Generate Candidates who got between 5 to 15 votes
-----------------------------------------------------------------
SELECT v.CandidateId, c.FirstName, c.LastName, COUNT(v.CandidateID) as NumberOfVotes
FROM Votes v
join (Select FirstName, LastName, CandidateID From Candidate) c
on c.CandidateID=v.CandidateID
GROUP BY c.FirstName,c.LastName,v.CandidateID
having COUNT(v.CandidateID) BETWEEN 5 AND 15
ORDER BY NumberOfVotes desc


--Generate all Candidates
-----------------------------------------------------------------
SELECT v.CandidateId, c.FirstName, c.LastName, COUNT(v.CandidateID) as NumberOfVotes
FROM Votes v
join (Select FirstName, LastName, CandidateID From Candidate) c
on c.CandidateID=v.CandidateID
GROUP BY c.FirstName,c.LastName,v.CandidateID
ORDER BY CandidateID asc;

--Generate all Candidates
-----------------------------------------------------------------
SELECT TOP 1 v.CandidateId, c.FirstName, c.LastName, COUNT(v.CandidateID) as NumberOfVotes
FROM Votes v
join (Select FirstName, LastName, CandidateID From Candidate) c
on c.CandidateID=v.CandidateID
GROUP BY c.FirstName,c.LastName,v.CandidateID
ORDER BY NumberOfVotes desc;
