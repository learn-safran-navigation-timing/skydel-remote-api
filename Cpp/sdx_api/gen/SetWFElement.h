#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Wavefront element properties. Properties define if an element is enabled/disabled, and the associated antenna.
    ///
    /// Name             Type   Description
    /// ---------------- ------ -------------------------------------------------------------------------------------------------
    /// Element          int    One-based index of the element. Value -1 adds a new element at the end of the list.
    /// Enabled          bool   If True, this antenna element will be simulated.
    /// AntennaModelName string Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.
    ///

    class SetWFElement;
    typedef std::shared_ptr<SetWFElement> SetWFElementPtr;
    
    
    class SetWFElement : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetWFElement();

      SetWFElement(int element, bool enabled, const std::string& antennaModelName);

      static SetWFElementPtr create(int element, bool enabled, const std::string& antennaModelName);
      static SetWFElementPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);
    };
    
  }
}

