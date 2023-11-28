#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFElement.
    ///
    /// Name             Type   Description
    /// ---------------- ------ -------------------------------------------------------------------------------------------------
    /// Element          int    One-based index of the element. Value -1 adds a new element at the end of the list.
    /// Enabled          bool   If True, this antenna element will be simulated.
    /// AntennaModelName string Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.
    ///

    class GetWFElementResult;
    typedef std::shared_ptr<GetWFElementResult> GetWFElementResultPtr;
    
    
    class GetWFElementResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFElementResult();

      GetWFElementResult(int element, bool enabled, const std::string& antennaModelName);

      GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName);

      static GetWFElementResultPtr create(int element, bool enabled, const std::string& antennaModelName);

      static GetWFElementResultPtr create(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName);
      static GetWFElementResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetWFElementResult);
  }
}

