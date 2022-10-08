type Bank struct {
    balance []int64
}


func Constructor(balance []int64) Bank {
    b := Bank{}
    b.balance = make([]int64, len(balance))
    copy(b.balance, balance)
    return b 
}

func (this *Bank) check(idx int) bool {
    return 1 <= idx && idx <= len(this.balance)
}


func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
    if this.check(account1) && this.check(account2) && money>=0 {
        if this.balance[account1-1] >= money {
            this.balance[account1-1] -= money
            this.balance[account2-1] += money
            return true
        } else {
            return false 
        }
        
    } else {
        return false 
    }
}


func (this *Bank) Deposit(account int, money int64) bool {
    if this.check(account) && money >= 0 {
        this.balance[account-1] += money
        return true 
    } else {
        return false 
    }
}


func (this *Bank) Withdraw(account int, money int64) bool {
    if this.check(account) && money >= 0 && this.balance[account-1] >= money {
        this.balance[account-1] -= money
        return true 
    } else {
        return false
    }
}