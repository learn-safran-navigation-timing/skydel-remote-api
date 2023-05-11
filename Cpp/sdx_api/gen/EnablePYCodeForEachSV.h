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
    /// Enable (or disable) P(Y)-Code for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1P", "L2P"
    /// Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class EnablePYCodeForEachSV;
    typedef std::shared_ptr<EnablePYCodeForEachSV> EnablePYCodeForEachSVPtr;
    
    
    class EnablePYCodeForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnablePYCodeForEachSV();

      EnablePYCodeForEachSV(const std::string& signal, const std::vector<bool>& enabled);

      static EnablePYCodeForEachSVPtr create(const std::string& signal, const std::vector<bool>& enabled);
      static EnablePYCodeForEachSVPtr dynamicCast(CommandBasePtr ptr);
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

