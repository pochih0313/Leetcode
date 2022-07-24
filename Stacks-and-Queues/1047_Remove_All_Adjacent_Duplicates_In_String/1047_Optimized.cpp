string removeDuplicates(string s) {
	string result = "";

	for (auto c : s) {
		if (!result.empty() && result.back() == c) {
			result.pop_back();
			continue;
		}
		result.push_back(c);
	}

	return result;
}
