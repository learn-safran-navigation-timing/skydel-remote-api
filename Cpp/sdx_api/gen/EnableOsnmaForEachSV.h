#pragma once

#include <memory>
#include "command_base.h"

#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) OSNMA for each Galileo's satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- -------------------------------------------------------------------------------------------------------------
    /// Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).
    ///

    class EnableOsnmaForEachSV;
    typedef std::shared_ptr<EnableOsnmaForEachSV> EnableOsnmaForEachSVPtr;
    
    
    class EnableOsnmaForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableOsnmaForEachSV();

      EnableOsnmaForEachSV(const std::vector<bool>& enabled);

      static EnableOsnmaForEachSVPtr create(const std::vector<bool>& enabled);
      static EnableOsnmaForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
    
  }
}

