#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetWFAntennaElementOffset is deprecated since 23.11. You may use GetVehicleAntennaOffset.
    /// 
    /// Get the WF antenna offset infos for this element.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class GetWFAntennaElementOffset;
    typedef std::shared_ptr<GetWFAntennaElementOffset> GetWFAntennaElementOffsetPtr;
    
    
    class GetWFAntennaElementOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetWFAntennaElementOffset();

      GetWFAntennaElementOffset(int element);

      static GetWFAntennaElementOffsetPtr create(int element);
      static GetWFAntennaElementOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

