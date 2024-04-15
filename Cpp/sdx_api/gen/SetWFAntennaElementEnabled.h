#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetWFAntennaElementEnabled is deprecated since 23.11. You may use SetWFElement.
    /// 
    /// Set WF antenna element enabled or disabled. A disabled antenna element is not simulated at all.
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------------------------
    /// Element int  One-based index for element in antenna.
    /// Enabled bool If True, this antenna element will bil simulated.
    ///

    class SetWFAntennaElementEnabled;
    typedef std::shared_ptr<SetWFAntennaElementEnabled> SetWFAntennaElementEnabledPtr;
    
    
    class SetWFAntennaElementEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetWFAntennaElementEnabled();

      SetWFAntennaElementEnabled(int element, bool enabled);

      static SetWFAntennaElementEnabledPtr create(int element, bool enabled);
      static SetWFAntennaElementEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

