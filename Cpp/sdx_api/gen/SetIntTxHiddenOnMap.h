#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a transmitter should be hidden on the map.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------
    /// HiddenOnMap bool   If true, transmitter will be hidden on the map.
    /// Id          string Transmitter unique identifier.
    ///

    class SetIntTxHiddenOnMap;
    typedef std::shared_ptr<SetIntTxHiddenOnMap> SetIntTxHiddenOnMapPtr;
    
    
    class SetIntTxHiddenOnMap : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxHiddenOnMap();

      SetIntTxHiddenOnMap(bool hiddenOnMap, const std::string& id);

      static SetIntTxHiddenOnMapPtr create(bool hiddenOnMap, const std::string& id);
      static SetIntTxHiddenOnMapPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** hiddenOnMap ****
      bool hiddenOnMap() const;
      void setHiddenOnMap(bool hiddenOnMap);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

