#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
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


      SetWFAntennaElementModel();

      SetWFAntennaElementModel(const std::string& antennaModelName, int element);

      static SetWFAntennaElementModelPtr create(const std::string& antennaModelName, int element);
      static SetWFAntennaElementModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

