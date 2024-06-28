#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.
    /// 
    /// Set WF Antenna model for this element
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------------------------------------------------------------
    /// AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.
    /// Element          int    One-based index for element in antenna.
    ///

    class SetWFAntennaElementModel;
    typedef std::shared_ptr<SetWFAntennaElementModel> SetWFAntennaElementModelPtr;
    
    
    class SetWFAntennaElementModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      SetWFAntennaElementModel();

      SetWFAntennaElementModel(const std::string& antennaModelName, int element);

      static SetWFAntennaElementModelPtr create(const std::string& antennaModelName, int element);
      static SetWFAntennaElementModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

