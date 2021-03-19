#pragma once

#include <memory>
#include "command_base.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnablePYForEachPrn is deprecated since 21.3. You may use EnablePYCodeForEachSV.
    /// 
    /// Enable (or disable) P(Y)-Code for each satellite individually.
    /// Allowed signal keys: "L1P", "L2P"
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------------------
    /// Signal  string     Signal key - see command description for possible values
    /// Enabled array bool Enable P(Y)-Code if True, otherwise it is P-Code only. Zero based index (index 0 => PRN 1, index 1 => PRN 2, etc).
    ///

    class EnablePYForEachPrn;
    typedef std::shared_ptr<EnablePYForEachPrn> EnablePYForEachPrnPtr;
    
    
    class EnablePYForEachPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnablePYForEachPrn();

      EnablePYForEachPrn(const std::string& signal, const std::vector<bool>& enabled);
  
      static EnablePYForEachPrnPtr create(const std::string& signal, const std::vector<bool>& enabled);
      static EnablePYForEachPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

