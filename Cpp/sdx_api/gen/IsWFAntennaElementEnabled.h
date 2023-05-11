#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether an antenna element is enabled or disabled.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class IsWFAntennaElementEnabled;
    typedef std::shared_ptr<IsWFAntennaElementEnabled> IsWFAntennaElementEnabledPtr;
    
    
    class IsWFAntennaElementEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsWFAntennaElementEnabled();

      IsWFAntennaElementEnabled(int element);

      static IsWFAntennaElementEnabledPtr create(int element);
      static IsWFAntennaElementEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

