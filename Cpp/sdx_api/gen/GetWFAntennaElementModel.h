#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetWFAntennaElementModel is deprecated since 23.11. You may use GetWFElement.
    /// 
    /// Get WF Antenna model for this element
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class GetWFAntennaElementModel;
    typedef std::shared_ptr<GetWFAntennaElementModel> GetWFAntennaElementModelPtr;
    
    
    class GetWFAntennaElementModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetWFAntennaElementModel();

      GetWFAntennaElementModel(int element);

      static GetWFAntennaElementModelPtr create(int element);
      static GetWFAntennaElementModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

