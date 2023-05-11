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
    /// Result of GetIntTxHiddenOnMap.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------
    /// HiddenOnMap bool   If true, transmitter will be hidden on the map.
    /// Id          string Transmitter unique identifier.
    ///

    class GetIntTxHiddenOnMapResult;
    typedef std::shared_ptr<GetIntTxHiddenOnMapResult> GetIntTxHiddenOnMapResultPtr;
    
    
    class GetIntTxHiddenOnMapResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxHiddenOnMapResult();

      GetIntTxHiddenOnMapResult(bool hiddenOnMap, const std::string& id);

      GetIntTxHiddenOnMapResult(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id);

      static GetIntTxHiddenOnMapResultPtr create(bool hiddenOnMap, const std::string& id);

      static GetIntTxHiddenOnMapResultPtr create(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id);
      static GetIntTxHiddenOnMapResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** hiddenOnMap ****
      bool hiddenOnMap() const;
      void setHiddenOnMap(bool hiddenOnMap);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIntTxHiddenOnMapResult);
  }
}

