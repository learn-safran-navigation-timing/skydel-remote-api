#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsWFAntennaElementEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------------------------
    /// Element int  One-based index for element in antenna.
    /// Enabled bool If True, this antenna element will bil simulated.
    ///

    class IsWFAntennaElementEnabledResult;
    typedef std::shared_ptr<IsWFAntennaElementEnabledResult> IsWFAntennaElementEnabledResultPtr;
    
    
    class IsWFAntennaElementEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsWFAntennaElementEnabledResult();

      IsWFAntennaElementEnabledResult(int element, bool enabled);

      IsWFAntennaElementEnabledResult(CommandBasePtr relatedCommand, int element, bool enabled);

      static IsWFAntennaElementEnabledResultPtr create(int element, bool enabled);

      static IsWFAntennaElementEnabledResultPtr create(CommandBasePtr relatedCommand, int element, bool enabled);
      static IsWFAntennaElementEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** element ****
      int element() const;
      void setElement(int element);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsWFAntennaElementEnabledResult);
  }
}

